/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:46:03 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/22 13:52:28 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd;
	int ret;
	int line;
	char *buff;

	(void)ac;
	line = 0;
	fd = open(av[1], O_RDWR);
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
	}
	printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
	if (ret == -1)
		printf("-----------\nError\n\n");
	else if (ret == 0)
		printf("-----------\nEnd of file\n\n");
	if (buff)
		free(buff);
	close(fd);
	system("leaks a.out");
	return (0);
}