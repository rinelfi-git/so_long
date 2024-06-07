/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:10:01 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 14:41:58 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include <stdlib.h>

static int	write_msg(t_exception *e, const char *desc)
{
	char	*msg;

	msg = "Error\n > Map must contain one and only one ";
	free(e->msg);
	e->msg = ft_strjoin(msg, desc);
	return (0);
}

int	check_unique(t_map *map, t_exception *e, char thing, const char *desc)
{
	int		x;
	int		y;
	int		thing_exists;

	y = -1;
	thing_exists = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->data[y][x] == thing)
			{
				if (thing_exists)
					return (write_msg(e, desc));
				thing_exists = 1;
			}
		}
	}
	return (thing_exists);
}
