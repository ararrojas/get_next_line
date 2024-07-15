/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:09:28 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/15 17:25:18 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;
	while(s[i] != '\0')
		i++;
	return(i);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t 	len;
	char	*dest;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*dest;

	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	if (slen > start)
		len = 0;
	if(len > slen - start)
		len = slen - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len && str[i + start])
	{
		dest[i] = str[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>
int main (void)
{
	char s1[] = "hola ";
	char s2[] = "que tal.";
	printf("%s\n", ft_strjoin(s1, s2));
}*/
