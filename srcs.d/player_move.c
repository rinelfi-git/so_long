/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:52:49 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 10:07:18 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	player_move(t_sprites *sprites, t_map *map)
{
	sprites->player->move++;
	open_door(sprites, map);
	ft_printf("%%> move %d\n", sprites->player->move);
}

void	player_up(t_sprites *sprites, t_map *map)
{
	int			locations[2];
	char		*chars[2];

	locations[0] = 0;
	locations[1] = 0;
	element_locate('P', map, locations);
	chars[0] = &map->data[locations[1] - 1][locations[0]];
	chars[1] = &map->data[locations[1]][locations[0]];
	if (*chars[0] == '1' || (*chars[0] == 'E' && !sprites->player->can_go))
		return ;
	if (*chars[0] == 'E' && sprites->player->can_go)
		sprites->exit->position = 2;
	else
		*chars[0] = 'P';
	*chars[1] = '0';
	sprites->player->position = 0;
	player_move(sprites, map);
}

void	player_down(t_sprites *sprites, t_map *map)
{
	int			locations[2];
	char		*chars[2];

	locations[0] = 0;
	locations[1] = 0;
	element_locate('P', map, locations);
	chars[0] = &map->data[locations[1] + 1][locations[0]];
	chars[1] = &map->data[locations[1]][locations[0]];
	if (*chars[0] == '1' || (*chars[0] == 'E' && !sprites->player->can_go))
		return ;
	if (*chars[0] == 'E' && sprites->player->can_go)
		sprites->exit->position = 4;
	else
		*chars[0] = 'P';
	*chars[1] = '0';
	sprites->player->position = 2;
	player_move(sprites, map);
}

void	player_left(t_sprites *sprites, t_map *map)
{
	int			locations[2];
	char		*chars[2];

	locations[0] = 0;
	locations[1] = 0;
	element_locate('P', map, locations);
	chars[0] = &map->data[locations[1]][locations[0] - 1];
	chars[1] = &map->data[locations[1]][locations[0]];
	if (*chars[0] == '1' || (*chars[0] == 'E' && !sprites->player->can_go))
		return ;
	if (*chars[0] == 'E' && sprites->player->can_go)
		sprites->exit->position = 5;
	else
		*chars[0] = 'P';
	*chars[1] = '0';
	sprites->player->position = 3;
	player_move(sprites, map);
}

void	player_right(t_sprites *sprites, t_map *map)
{
	int			locations[2];
	char		*chars[2];

	locations[0] = 0;
	locations[1] = 0;
	element_locate('P', map, locations);
	chars[0] = &map->data[locations[1]][locations[0] + 1];
	chars[1] = &map->data[locations[1]][locations[0]];
	if (*chars[0] == '1' || (*chars[0] == 'E' && !sprites->player->can_go))
		return ;
	if (*chars[0] == 'E' && sprites->player->can_go)
		sprites->exit->position = 3;
	else
		*chars[0] = 'P';
	*chars[1] = '0';
	sprites->player->position = 1;
	player_move(sprites, map);
}
