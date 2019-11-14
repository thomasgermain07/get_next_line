/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:34:39 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/14 11:41:56 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_check_buffer(char *buffer)
{
	size_t size;

	size = 0;
	while (buffer[size])
	{
		if (buffer[size] == '\n')
			return (size);
		if (buffer[size] == '\0')
			return (-BUFFER_SIZE);
		size++;
	}
	return (-1);
}

	int		create_line(char *buffer, t_line **chain)
{
	int				i;
	static char 	*str = NULL;

	i = ft_check_buffer(buffer);
	if (i >= 0)
	{
		ft_listadd_back(chain, ft_lstnew(ft_strjoin(str, buffer, i)));
		return (1);
	}
	else if (i < 0 && i > BUFFER_SIZE)
	{
		str = ft_strjoin(str, buffer, ft_strlen(buffer));
		return (0);
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	t_line			**chain;
	int				size;

	if (!(chain = malloc(sizeof(t_line *))))
		return (-1);
	*chain = NULL;
	while ((size = read(fd, buffer, BUFFER_SIZE - 1)))
	{
		buffer[size] = '\0';
		create_line(buffer, chain);
		break;
	}
	*line = (*chain)->line;
	return (0);
}
