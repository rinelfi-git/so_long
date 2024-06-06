/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:40:27 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 15:25:40 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static void	sprites_destruct(t_node *self)
{
	t_sprites	*cast;

	cast = (t_sprites *)self;
	img_free(cast->wall, cast->x);
	img_free(cast->floor, cast->x);
	img_free(cast->collectible, cast->x);
	cast->player->destruct(cast->player, cast->x);
	cast->exit->destruct(cast->exit, cast->x);
	free(cast);
}

t_sprites	*sprites_init(void *x)
{
	t_sprites	*init;

	init = (t_sprites *)malloc(sizeof(t_sprites));
	if (!init)
		exit(1);
	init->x = x;
	init->componemt.prev = 0;
	init->componemt.next = 0;
	init->componemt.destruct = sprites_destruct;
	init->wall = img_new("wall.xpm", x);
	init->floor = img_new("floor.xpm", x);
	init->collectible = img_new("collectible.xpm", x);
	init->player = player_new(x);
	init->exit = exit_new(x);
	return (init);
}
