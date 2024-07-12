/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:09:28 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/12 12:00:58 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;
	while(s[i] != '\0')
		i++;
	return(i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
