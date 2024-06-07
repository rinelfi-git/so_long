/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outlines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:12:13 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 13:26:50 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include <stdlib.h>

static int	check_vertical(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->data[i][0] != '1' || map->data[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_horizontal(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->data[0][i] != '1' || map->data[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_outlines(t_map *map, t_exception *e)
{
	if (!check_vertical(map) || !check_horizontal(map))
	{
		free(e->msg);
		e->msg = ft_strdup("Error\n > Map outlines must be walls\n");
		return (0);
	}
	return (1);
}
