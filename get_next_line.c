/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:50:56 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/17 16:58:14 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// option == I_LINE : return the index of the \n
// option == NB_LINE : return the nb of line
int			ft_check_buffer(char *buffer, int option)
{
	int				size;
	int				nb;

	nb		= 0;
	size	= 0;
	while (buffer[size])
	{
		if (buffer[size] == '\n')
		{
			if (option == I_LINE)
				return (size);
			else if (option == NB_LINE)
				nb++;
		}
		size++;
	}
	if (option == NB_LINE)
		return (nb);
	return (-1);
}

int				ft_assigning(char *str, char **line)
{
	static int		last;
	int				i;
	int				current_nb_line;

	current_nb_line = ft_check_buffer(str, NB_LINE);
	i = 0;
	if (current_nb_line <= last)
		return (0);
	while (i < last)
	{
		str = str + (ft_check_buffer(str, I_LINE) + 1);
		i++;
	}
	*line = ft_strjoin(*line, str, ft_check_buffer(str, I_LINE));
	last++;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	int 			size;
	static char		*str;

	*line	= NULL;
	if (!BUFFER_SIZE)
		return (-1);
	while ((size = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[size] = '\0';
		str = ft_strjoin(str, buffer, size);
		if (ft_assigning(str, line))
			return (1);
	}
	return (0);
}
