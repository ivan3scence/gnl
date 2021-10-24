#include "get_next_line_bonus.h"

static char	*ft_rebuf(char *buf, int i)
{
	int		n;
	char	*new_buf;

	n = -1;
	new_buf = (char *)malloc(sizeof(char) * (i + BUFFER_SIZE));
	if (!new_buf)
		return (NULL);
	while (++n < i)
		new_buf[n] = buf[n];
	free(buf);
	buf = new_buf;
	return (buf);
}

char	*get_next_line_fd(int fd, t_list *elem, int ii, int i)
{
	static char	*buf;

	buf = (char *)malloc(sizeof(char) * ii);
	if (!buf)
		return (NULL);
	while (read(fd, &buf[i], 1) == 1)
	{
		if (i + 1 >= ii)
		{
			buf = ft_rebuf(buf, ii);
			ii += BUFFER_SIZE;
			if (!buf)
				return (NULL);
		}
		if (buf[i++] == '\n')
			break ;
	}
	if (!i)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	elem->index += i;
	return (buf);
}

t_list	*ft_create_elem(int fd)
{
	t_list	*element;

	element = NULL;
	element = (t_list *) malloc(sizeof(t_list));
	if (element)
	{
		element->index = 0;
		element->fd = fd;
		element->next = NULL;
	}
	return (element);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*f;

	if (!(lst && new))
		return ;
	if (*lst)
	{
		f = ft_lstlast(*lst);
		f->next = new;
	}
	else
		*lst = new;
}

static t_list	*ft_find_fd(t_list **lst, int fd)
{
	t_list	*elem;

	if (!(lst && *lst))
		return (0);
	elem = *lst;
	while (elem)
	{
		if (elem->fd == fd)
			return (elem);
		elem = elem->next;
	}
	return (0);
}

static t_list	*get_elem(t_list **lst, int fd)
{
	t_list	*element;

	element = ft_find_fd(lst, fd);
	if (element)
		return(element);
	element = ft_create_elem(fd);
	ft_lstadd_back(lst, element);
	return (element);
}

static void	get_read_until_index(int fd, int index)
{
	int		i;
	char	temp;

	i = 0;
	while (i++ != index)
        	read(fd, &temp, 1);
}
char	*get_next_line(int fd)
{
	int	buf_size;
	static t_list	*elem;
	t_list	**lst;
	int	i;

	i = 0;
	elem = 0;
	lst = &elem;
	buf_size = BUFFER_SIZE;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (fd < 0)
		return (0);
	else
	{
		elem = get_elem(lst, fd);
		if (elem->index)
			get_read_until_index(fd, elem->index);
		return (get_next_line_fd(fd, elem, buf_size, i));
	}
}
