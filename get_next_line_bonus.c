/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:10:52 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/22 17:10:56 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*join_and_free(char *static_buf, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(static_buf, buffer);
	if (temp == NULL)
		return (NULL);
	return (temp);
}

char	*get_next(char *static_buf)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (static_buf[i] && static_buf[i] != '\n')
		i++;
	if (!static_buf[i])
	{
		free(static_buf);
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char) * (ft_strlen(static_buf) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (static_buf[i])
		next_line[j++] = static_buf[i++];
	next_line[j] = '\0';
	free(static_buf);
	return (next_line);
}

char	*get_line(char *static_buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_buf[i])
		return (NULL);
	while (static_buf[i] && static_buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buf[i] && static_buf[i] != '\n')
	{
		line[i] = static_buf[i];
		i++;
	}
	if (static_buf[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *static_buf)
{
	int		byte_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!static_buf || (!ft_strchr(static_buf, '\n') && (byte_read > 0)))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		static_buf = join_and_free(static_buf, buffer);
	}
	free(buffer);
	return (static_buf);
}

char	*get_next_line(int fd)
{
	static char	*static_buf[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buf[fd] = read_line(fd, static_buf[fd]);
	if (!static_buf[fd])
		return (NULL);
	line = get_line(static_buf[fd]);
	static_buf[fd] = get_next(static_buf[fd]);
	return (line);
}
