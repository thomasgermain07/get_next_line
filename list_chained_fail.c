/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:34:39 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/15 09:47:40 by thgermai         ###   ########.fr       */
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

int			create_line(char *buffer, t_line **chain, char **str)
{
	int				i;

	printf("start str : %s -|\n", *str);
	i = ft_check_buffer(buffer);
	if (i > 0)
	{
		ft_listadd_back(chain, ft_lstnew(ft_strjoin(*str, buffer, i)));
		printf("line created\n");
		create_line(buffer + i + 1, chain, str);
		*str = NULL;
		return (1);
	}
	else if (i <= 0 && i < BUFFER_SIZE)
	{
		*str = ft_strjoin(*str, buffer, ft_strlen(buffer));
		printf("half str : %s -|\n", *str);
		return (0);
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	char			*str;
	t_line			**chain;
	int				size;

	if (!(chain = malloc(sizeof(t_line *))))
		return (-1);
	*chain = NULL;
	int count = 0;
	while ((size = read(fd, buffer, BUFFER_SIZE - 1)) && count < 2)
	{
		buffer[size] = '\0';
		create_line(buffer, chain, &str);
		printf("gnl str : %s\n", str);
		printf("buffer reset\n\n");
		count++;
	}
	if (*chain)
	{
		*line = (*chain)->line;
		while (*chain)
		{
			printf("%s\n", (*chain)->line);
			*chain = (*chain)->next;
		}
	}
	return (0);
}
