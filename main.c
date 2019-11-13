/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:46:03 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/13 23:10:02 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main()
{
	int		fd;
	char	*line;
	char	file_name[] = "text_file.txt";

	line = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		printf("Open failed\n");
		return (0);
	}

	get_next_line(fd, &line);
	//printf("%s\n", line);
	// get_next_line(fd, &line);
	// printf("%s\n", line);

	close (fd);

	return (0);
}
