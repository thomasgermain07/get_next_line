/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:46:03 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/18 16:02:08 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	(void)ac;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		printf("Open failed\n");
		return (0);
	}

	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}

	close (fd);

	while (1)
		;

	return (0);
}
