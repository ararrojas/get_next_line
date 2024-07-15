/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:07:01 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/15 15:09:07 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int 	fd;
	char	*line;

	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 18);
		else
		{
			line = get_next_line(fd);
			while(line)
			{
				printf("%s \n", line);
				free(line);
				printf("------------\n");
				line = get_next_line(fd);
			}
			close(fd);
		}
	}
	return (0);
}
