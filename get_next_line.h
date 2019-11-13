/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:31:10 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/13 16:55:46 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 21

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char *s1, char *s2, int size);
int					ft_strlen(char *s);

#endif
