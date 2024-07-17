/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:07:01 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/17 14:44:06 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int 	fd;
	char	*line;
	int		count; // line numbers

	count = 0;
	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 18);
		while (fd)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			count++;
			printf("LINE [%d] =\n%s\n", count, line);
			printf("------------\n");
			free(line);
			line = NULL;
		}
		close(fd);
	}
	return (0);
}
