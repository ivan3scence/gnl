/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:57:09 by sdonny            #+#    #+#             */
/*   Updated: 2021/10/21 18:57:13 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int	fd;
	int	index;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	50
#endif

#if BUFFER_SIZE <= 0
# undef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif
