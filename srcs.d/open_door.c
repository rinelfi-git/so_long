/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:25:02 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 20:51:51 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	collectible_exists(t_map *map)
{
	int	xy[2];

	xy[0] = 0;
	while (xy[0] < map->height)
	{
		xy[1] = 0;
		while (xy[1] < map->width)
		{
			if (map->data[xy[0]][xy[1]] == 'C')
				return (1);
			xy[1]++;
		}
		xy[0]++;
	}
	return (0);
}

void	open_door(t_sprites *sprites, t_map *map)
{
	if (!collectible_exists(map) && !sprites->exit->position)
	{
		sprites->exit->position = 1;
		sprites->player->can_go = 1;
	}
}
