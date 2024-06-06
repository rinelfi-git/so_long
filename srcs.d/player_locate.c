/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_locate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:06:26 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 21:32:55 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_locate(t_map *map, int *locations)
{
	locations[1] = 0;
	while (locations[1] < map->height)
	{
		locations[0] = 0;
		while (locations[0] < map->width)
		{
			if (map->data[locations[1]][locations[0]] == 'P')
				return ;
			locations[0]++;
		}
		locations[1]++;
	}
	locations[1] = -1;
	locations[0] = -1;
}
