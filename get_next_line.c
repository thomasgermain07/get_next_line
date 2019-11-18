/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:50:56 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/18 16:01:29 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(char *s)
{
	size_t		size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || (start + len > ft_strlen(s)))
		return (sub = ft_strdup("\0"));
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s = s + start;
	ft_strlcpy(sub, s, len + 1);
	sub[len] = '\0';
	return (sub);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int				get_next_line(int fd, char **line)
{
	static char		*stock;
	char			*buffer;
	int				ret;
	int				i;

	if (BUFFER_SIZE <= 0 || !line || !(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!stock)
		stock = ft_calloc(0,0);
	while (!ft_strchr(buffer, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	*line = ft_substr(stock, 0, i);
	stock = ft_strdup(stock + i + 1);
	free(buffer);
	if (ft_strlen(*line))
		return (1);
	else
	{
		free(stock);
		return (0);
	}
}
