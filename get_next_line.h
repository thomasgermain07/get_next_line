/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:31:10 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/21 21:55:32 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

int					get_next_line(int fd, char **line);
char				*ft_strdup(char *s1);
char				*ft_strchr(char *s, int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(char *s);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
