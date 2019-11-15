/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:31:10 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/15 16:11:06 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 2
# define NB_LINE 2
# define I_LINE 1

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
