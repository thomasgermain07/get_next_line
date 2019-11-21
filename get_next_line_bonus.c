/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:50:56 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/21 21:54:17 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || (start + len > ft_strlen(s)))
		return (sub = (char *)malloc(sizeof(char)));
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
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
		temp = ft_strdup(stock + i);
		free(stock);
		stock = temp;
	}
	return (stock);
}

int				ft_exit(int ret, char **buffer, char **stock)
{
	if (ret == 0)
	{
		if (*stock)
		{
			free(*stock);
			*stock = NULL;
		}
	}
	if (ret >= 0 && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
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
		!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ft_exit(-1, &buffer, &stock[fd]));
	if (!stock[fd])
		stock[fd] = malloc(sizeof(char));
	while (!ft_strchr(buffer, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		stock[fd] = ft_strjoin(stock[fd], buffer);
	}
	i = 0;
	while (stock[fd][i] && stock[fd][i] != '\n')
		i++;
	*line = ft_substr(stock[fd], 0, i);
	stock[fd] = ft_refresh_stock(stock[fd], i);
	if (ret || stock[fd][0])
		return (ft_exit(1, &buffer, &stock[fd]));
	return (ft_exit(0, &buffer, &stock[fd]));
}
