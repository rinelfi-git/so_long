/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:44 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 12:10:40 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# ifndef BUFFER_SIZE
/**
 * Default buffer size at 1Mb
*/
#  define BUFFER_SIZE 1048576
# endif

char	*get_next_line(int fd);
size_t	ft_seek(char *s);
char	*fill(char *str, char *buffer, size_t seek);
void	clean_left(char *buff, size_t seeker);
#endif