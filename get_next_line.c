/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:01:41 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/17 14:28:10 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*join_and_free(char *file, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(file, buffer);
	free(file);
	return (temp);
}

char	*get_next(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_line(char *file, int fd)
{
	int		char_read;
	char	*buffer;

	if (!file)
		file = ft_calloc(1, 1);
	char_read = 1;
	buffer = ft_calloc(sizeof(char), (BUFF_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(file, '\n') && char_read > 0)
	{
		char_read = read(fd, buffer, BUFF_SIZE);
		if (char_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[char_read] = '\0';
		file = join_and_free(file, buffer);
	}
	free(buffer);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buffer = read_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	buffer = get_next(buffer);
	return (line);
}
