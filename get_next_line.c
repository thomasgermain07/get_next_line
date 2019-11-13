/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:34:39 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/13 23:43:51 by thomasgerma      ###   ########.fr       */
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
		printf("create_line i = %i\n", i);
		ft_listadd_back(chain, ft_lstnew(ft_strjoin(str, buffer, i)));
		printf("First done\n");
		str = NULL;
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
	static t_line	**chain;
	int				size;

	while ((size = read(fd, buffer, BUFFER_SIZE - 1)))
	{
		buffer[size] = '\0';
		create_line(buffer, chain);
		break;
	}
	*line = (*chain)->line;
	return (0);
}
