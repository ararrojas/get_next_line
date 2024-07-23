/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:07:01 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/23 13:16:36 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"


// sin bonus
int	main(int ac, char **av)
{
	int 	fd;
	char	*line;
	int		count; // line numbers

	count = 0;
	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
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
/*
// bonus - leaks in this main for bonus

int	main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		count;
	char	*line;

	count = 1;
	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	if (fd == -1 || fd2 == -1 || fd3 == -1)
		write(1, "Cannot read file.\n", 18);
	while (fd && fd2 && fd3)
	{
		line = get_next_line(fd);
		line = get_next_line(fd2);
		line = get_next_line(fd3);
		if (line)
		{
			free(line);
			printf("line [%d]: %s", count, line);
			printf("------------\n");
			if (line == NULL)
			break ;
			
			printf("line [%d]: %s", count, line);
			printf("------------\n");
			if (line == NULL)
			break ;
			
			printf("line [%d]: %s", count, line);
			printf("------------\n");
			count++;
			line = NULL;
		}
	}
	count = 1;
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}*/
