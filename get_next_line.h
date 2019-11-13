/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:31:10 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/13 23:11:12 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 210

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char *s1, char *s2, int size);
int					ft_strlen(char *s);
t_line				*ft_lstnew(char *str);
void				ft_listadd_back(t_line **list, t_line *new);

#endif
