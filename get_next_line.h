/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:43:17 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/17 12:41:26 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 10
# endif

char	*join_and_free(char *file, char *buffer);
char	*get_next(char *buffer);
char	*get_line(char *buffer);
char	*read_line(char *file, int fd);
char	*get_next_line(int fd);
//utils
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
