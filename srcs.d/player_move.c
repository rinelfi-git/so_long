/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:52:49 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 14:52:08 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

static void	get_player_coordinate(t_map *map, int *x, int *y)
{
	*y = 0;
	while (*y < map->height)
	{
		*x = 0;
		while (*x < map->width)
		{
			if (map->data[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	player_up(t_player *player, t_map *map)
{
	int	x;
	int	y;

	get_player_coordinate(map, &x, &y);
	if (map->data[y - 1][x] == '0' || map->data[y - 1][x] == 'C')
	{
		map->data[y - 1][x] = 'P';
		map->data[y][x] = '0';
		player->move++;
		player->position = 0;
		ft_printf("Mouvement %d\n", player->move);
	}
}

void	player_down(t_player *player, t_map *map)
{
	int	x;
	int	y;

	get_player_coordinate(map, &x, &y);
	if (map->data[y + 1][x] == '0' || map->data[y + 1][x] == 'C')
	{
		map->data[y + 1][x] = 'P';
		map->data[y][x] = '0';
		player->move++;
		player->position = 2;
		ft_printf("Mouvement %d\n", player->move);
	}
}

void	player_left(t_player *player, t_map *map)
{
	int	x;
	int	y;

	get_player_coordinate(map, &x, &y);
	if (map->data[y][x - 1] == '0' || map->data[y][x - 1] == 'C')
	{
		map->data[y][x - 1] = 'P';
		map->data[y][x] = '0';
		player->move++;
		player->position = 3;
		ft_printf("Mouvement %d\n", player->move);
	}
}

void	player_right(t_player *player, t_map *map)
{
	int	x;
	int	y;

	get_player_coordinate(map, &x, &y);
	if (map->data[y][x + 1] == '0' || map->data[y][x + 1] == 'C')
	{
		map->data[y][x + 1] = 'P';
		map->data[y][x] = '0';
		player->move++;
		player->position = 1;
		ft_printf("Mouvement %d\n", player->move);
	}
}
