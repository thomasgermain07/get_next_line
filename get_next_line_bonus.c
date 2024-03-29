/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:50:56 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/22 14:57:46 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	i;

	i = -1;
	if (!(temp = malloc(count * size)))
		return (NULL);
	if (!count || !size)
		return (temp);
	while (++i < count * size)
		((unsigned char *)temp)[i] = '\0';
	return (temp);
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || (start + len > ft_strlen(s)))
		return (sub = (char *)ft_calloc(sizeof(char), 1));
	if (!(sub = (char *)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	s = s + start;
	ft_strlcpy(sub, s, len + 1);
	sub[len] = '\0';
	return (sub);
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
		free(stock);
		stock = NULL;
	}
	return (stock);
}

int				ft_exit(int ret, char **buffer, char **stock)
{
	if (ret >= 0 && (*buffer || *stock))
	{
		if (*buffer)
			free(*buffer);
		if (ret == 0 && *stock)
			free(*stock);
	}
	if (ret == -1)
	{
		if (!*buffer)
			free(*buffer);
		if (*stock)
			free(*stock);
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char		*stock[1024];
	char			*buffer;
	int				ret;
	int				i;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > 1024 ||
		!(buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (ft_exit(-1, &buffer, &stock[fd]));
	if (!stock[fd])
		stock[fd] = (char *)ft_calloc(sizeof(char), 1);
	while (!ft_strchr(buffer, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (ft_exit(-1, &buffer, &stock[fd]));
		buffer[ret] = '\0';
		stock[fd] = ft_strjoin(stock[fd], buffer);
	}
	i = 0;
	while (stock[fd][i] && stock[fd][i] != '\n')
		i++;
	*line = ft_substr(stock[fd], 0, i);
	stock[fd] = ft_refresh_stock(stock[fd], i);
	if (ret || stock[fd])
		return (ft_exit(1, &buffer, &stock[fd]));
	return (ft_exit(0, &buffer, &stock[fd]));
}
