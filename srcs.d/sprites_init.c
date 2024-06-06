/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:40:27 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 14:50:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static void img_free(t_img *img, void *x)
{
	free(img->path);
	mlx_destroy_image(x, img->img);
	free(img);
}

static void	sprites_destruct(t_node *self)
{
	t_sprites	*cast;

	cast = (t_sprites *)self;
	img_free(cast->wall, cast->x);
	img_free(cast->floor, cast->x);
	img_free(cast->collectible, cast->x);
	cast->player->destruct(cast->player, cast->x);
	img_free(cast->exit_close, cast->x);
	img_free(cast->exit_open, cast->x);
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
	init->exit_close = img_new("door-close.xpm", x);
	init->exit_open = img_new("door-open.xpm", x);
	return (init);
}
