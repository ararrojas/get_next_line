/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:43:17 by arojas-a          #+#    #+#             */
/*   Updated: 2024/07/12 11:52:30 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFF_SIZE
# define BUFF_SIZE 1000
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif
