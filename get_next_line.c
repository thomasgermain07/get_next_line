/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:50:56 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/21 11:40:42 by thgermai         ###   ########.fr       */
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

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || (start + len > ft_strlen(s)))
		return (sub = ft_calloc(0, 0));
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s = s + start;
	ft_strlcpy(sub, s, len + 1);
	sub[len] = '\0';
	return (sub);
}

void			*ft_memset(void *b, int c, size_t len)
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

char			*ft_refresh_stock(char *stock, int i)
{
	char			*temp;

	if (stock[i])
	{
		temp = ft_strdup(stock + i + 1);
		free(stock);
		stock = temp;
	}
	else
	{
		temp = ft_strdup(stock + i);
		free(stock);
		stock = temp;
	}
	return (stock);
}

int				get_next_line(int fd, char **line)
{
	static char		*stock;
	char			*buffer;
	int				ret;
	int				i;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > 10240 ||
		!(buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (-1);
	if (!stock)
		stock = ft_calloc(0, 0);
	while (!ft_strchr(buffer, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	*line = ft_substr(stock, 0, i);
	stock = ft_refresh_stock(stock, i);
	free(buffer);
	if (!(!ret && !stock[0]))
		return (1);
	free(stock);
	return (0);
}
