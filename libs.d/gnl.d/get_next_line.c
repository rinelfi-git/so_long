/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:42:52 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 12:12:04 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*gnl_logic(int fd, char *buffer, ssize_t *read_byte)
{
	char	*ret;
	int		loop;

	ret = NULL;
	loop = 1;
	while (loop)
	{
		if (!ft_strlen(buffer))
			*read_byte = read(fd, buffer, BUFFER_SIZE);
		if (*read_byte > 0)
		{
			ret = fill(ret, buffer, ft_seek(buffer));
			clean_left(buffer, ft_seek(buffer));
			if (!ret)
				loop = 0;
			if (loop && ret[ft_strlen(ret) - 1] == '\n')
				return (ret);
		}
		else
			loop = 0;
	}
	*read_byte = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (gnl_logic(fd, buffer, &read_byte));
}
