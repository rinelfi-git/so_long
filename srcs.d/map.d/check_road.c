/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:12:48 by erijania          #+#    #+#             */
/*   Updated: 2024/07/15 11:13:32 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include <stdlib.h>

static void	fill(t_map *map, int y, int x)
{
	char	*c;
	int		yx[2];

	if (y < 1 || y >= map->height - 1 || x < 1 || x >= map->width - 1)
		return ;
	c = &map->data[y][x];
	element_locate('C', map, yx);
	if (*c == 'x' || *c == '1' || (*c == 'E' && yx[0] > 0 && yx[1] > 0))
		return ;
	else
	{
		*c = 'x';
		fill(map, y - 1, x);
		fill(map, y, x - 1);
		fill(map, y, x + 1);
		fill(map, y + 1, x);
	}
}

static void	transform(t_map *map)
{
	int		xy[2];

	element_locate('P', map, xy);
	fill(map, xy[1], xy[0]);
	element_locate('E', map, xy);
	fill(map, xy[1], xy[0]);
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
		e->msg = ft_strjoin("Error\n",
				" > Player cannot collect all collectibles\n");
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
