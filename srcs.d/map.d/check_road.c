/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:12:48 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 13:53:19 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include <stdlib.h>

static void	get_neighbors(t_map *map, const int *xy, char *neighbors)
{
	if (xy[0] == 0)
		neighbors[0] = 0;
	else
		neighbors[0] = map->data[xy[0] - 1][xy[1]];
	if (xy[1] == map->width - 1)
		neighbors[1] = 0;
	else
		neighbors[1] = map->data[xy[0]][xy[1] + 1];
	if (xy[0] == map->height - 1)
		neighbors[2] = 0;
	else
		neighbors[2] = map->data[xy[0] + 1][xy[1]];
	if (xy[1] == 0)
		neighbors[3] = 0;
	else
		neighbors[3] = map->data[xy[0]][xy[1] - 1];
}

static void update_neighbors(t_map *map, int *xy, const char *neighbors, int *loop)
{
	map->data[xy[0]][xy[1]] = 'x';
	if (neighbors[0] != 0 && neighbors[0] != '1')
		map->data[xy[0] - 1][xy[1]] = 'x';
	if (neighbors[1] != 0 && neighbors[1] != '1')
		map->data[xy[0]][xy[1] + 1] = 'x';
	if (neighbors[2] != 0 && neighbors[2] != '1')
		map->data[xy[0] + 1][xy[1]] = 'x';
	if (neighbors[3] != 0 && neighbors[3] != '1')
		map->data[xy[0]][xy[1] - 1] = 'x';
	*loop = 1;
}

static int	need_update_neighbor(t_map *map, int *xy, const char *neighbors)
{
	if (map->data[xy[0]][xy[1]] != 'x')
		return (1);
	if (neighbors[0] != 0 && neighbors[0] != '1'
		&& map->data[xy[0] - 1][xy[1]] != 'x')
		return (1);
	if (neighbors[1] != 0 && neighbors[1] != '1'
		&& map->data[xy[0]][xy[1] + 1] != 'x')
		return (1);
	if (neighbors[2] != 0 && neighbors[2] != '1'
		&& map->data[xy[0] + 1][xy[1]] != 'x')
		return (1);
	if (neighbors[3] != 0 && neighbors[3] != '1'
		&& map->data[xy[0]][xy[1] - 1] != 'x')
		return (1);
	return (0);
}

static void	transform(t_map *map)
{
	int		xy[2];
	int		loop;
	char	neighbors[4];

	loop = 1;
	while (loop)
	{
		loop = 0;
		xy[0] = -1;
		while (++xy[0] < map->height)
		{
			xy[1] = -1;
			while (++xy[1] < map->width)
			{
				if (map->data[xy[0]][xy[1]] == 'P' || map->data[xy[0]][xy[1]] == 'x')
				{
					get_neighbors(map, xy, neighbors);
					if (need_update_neighbor(map, xy, neighbors))
						update_neighbors(map, xy, neighbors, &loop);
				}
			}
		}
	}
}

int	check_road(t_map *map, t_exception *e)
{
	t_map	*clone;
	int		loc[2];

	clone = map_new(map->path);
	transform(clone);
	element_locate('C', clone, loc);
	if (loc[0] > 0 && loc[1] > 0)
	{
		clone->component.destruct((t_node *) clone);
		free(e->msg);
		e->msg = ft_strdup("Error\n > Player cannot collect all collectibles\n");
		return (0);
	}
	element_locate('E', clone, loc);
	clone->component.destruct((t_node *) clone);
	if (loc[0] > 0 && loc[1] > 0)
	{
		free(e->msg);
		e->msg = ft_strdup("Error\n > Player cannot quit the map\n");
		return (0);
	}
	return (1);
}
