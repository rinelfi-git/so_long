/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:38:58 by erijania          #+#    #+#             */
/*   Updated: 2024/07/11 11:20:28 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	check_path(const char *path, t_exception *e)
{
	int		fd;
	int		valid;
	char	buffer[1];

	fd = open(path, O_RDONLY);
	valid = read(fd, buffer, 0) >= 0;
	close(fd);
	if (!valid)
	{
		free(e->msg);
		e->msg = ft_strjoin(
				"Error\n > Give me a path to a file. Not a directory ",
				"nor a poney nor banana.\n"
				);
	}
	return (valid);
}
