/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:34:39 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/13 17:51:01 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			check_buffer(char *buffer)
{
	size_t size;

	size = 0;
	while (buffer[size])
	{
		if (buffer[size] == '\n')
			return (size);
		size++;
	}
	return (-1);
}

t_line		*ft_create_t_line(char *str)
{
	t_line		*line;

	if (!(line = malloc(sizeof(t_line) * 1)))
		return (NULL);
	line->line = str;
	line->next = NULL;
	return (line);
}

void		create_line(char *buffer, t_line **list)
{
	static char		*str;
	int				i;
	int				count;

	count = 0;
	while (count < ft_strlen(buffer))
	{
		i = check_buffer(buffer);
		if (i == -1)
		{
			str = ft_strjoin(str, buffer, ft_strlen(buffer));
			return ;
		}
		else
		{
			str = ft_strjoin(str, buffer, i);
			while ((*list)->next)
				(*list) = (*list)->next;
			(*list)->next = ft_create_t_line(str);
			count += i;
			buffer += i;
		}
	}
}

int				get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE];
	t_line		*list;
	int			size;

	if (!(list = malloc(sizeof(t_line) * 1)))
		return (-1);
	list->next = NULL;
	while ((size = read(fd, buffer, BUFFER_SIZE - 1)))
	{
		buffer[size] = '\0';
		create_line(buffer, &list);
	}
	(void)line;
	return (0);
}
