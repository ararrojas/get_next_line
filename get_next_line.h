/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:43:17 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/15 17:30:55 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFF_SIZE
# define BUFF_SIZE 1
# endif

void	*free_line(char **buffer);
char	*get_next(char *buffer);
char	*get_line(char *buffer);
char	*read_line(char *file, int fd);
char	*get_next_line(int fd);
char	*free_buffer(char *file, char *buffer);
//utils
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
