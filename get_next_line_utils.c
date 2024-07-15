/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:09:28 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/15 16:01:55 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	while(s[i] != '\0')
		i++;
	return(i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;

	c = ch;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *line, char *temp)
{
	size_t	i;
	size_t	j;
	size_t 	len;
	char	*join;

	len = ft_strlen(line) + ft_strlen(temp);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		join[i] = line[i];
		i++;
	}
	while (temp[j])
	{
		join[i] = temp[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}
/*#include <stdio.h>
int main (void)
{
	char line[] = "hola ";
	char temp[] = "que tal.";
	printf("%s\n", ft_strjoin(line, temp));
}*/
