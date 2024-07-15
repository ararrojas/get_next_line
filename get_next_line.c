/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:01:41 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/15 16:01:42 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *free_line(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
	return (NULL);
}

char	*create_line(char *line, int fd)
{
	int		char_read;
	char	*temp;
	
	char_read = 1;
	temp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!temp)
		return (free_line(&line));
	temp[0] = '\0';

	while (!ft_strchr(line, '\n') && char_read > 0)
	{
		char_read = read(fd, temp, BUFF_SIZE);
		if (char_read > 0)
		{
			temp[char_read] = '\0';
			line = ft_strjoin(line, temp);
			if (!line)
				return (free_line(&temp));
		}
	}

	free(temp);

	if (char_read == -1)
		return (free_line(&line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	
	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = create_line(line, fd);
	if (!line)
		return (NULL);
	return (line);
}
