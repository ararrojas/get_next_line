/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:01:41 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/12 12:18:06 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFF_SIZE + 1];
	size_t		bytes_read;
	char		*line;
	
	if (fd < 0 || buffer <= 0)
		return (NULL);
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFF_SIZE);
		line = ft_strdup(buffer);
		buffer[bytes_read] = '\0';
		return (line);
	}
	return (NULL);
}
