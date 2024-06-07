/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:48:13 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 14:28:11 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manager.h"
#include "so_long.h"
#include "mlx.h"

static void	render_at(t_frame *frame, t_img *img, int *locations)
{
	mlx_put_image_to_window(frame->x,
		frame->display,
		img->img,
		TILE_WIDTH * locations[1],
		TILE_HEIGHT * locations[0]);
}

void	frame_repaint(t_frame *self)
{
	int			locs[2];
	t_img		*img;
	t_map		*map;
	t_sprites	*sprites;

	map = (t_map *)node_get(self->components, 0);
	sprites = (t_sprites *)node_get(self->components, 1);
	locs[0] = -1;
	while (++locs[0] < map->height)
	{
		locs[1] = -1;
		while (++locs[1] < map->width)
		{
			img = sprites->floor;
			if (map->data[locs[0]][locs[1]] == '1')
				img = sprites->wall;
			else if (map->data[locs[0]][locs[1]] == 'P')
				img = sprites->player->img[sprites->player->position];
			else if (map->data[locs[0]][locs[1]] == 'C')
				img = sprites->collectible;
			else if (map->data[locs[0]][locs[1]] == 'E')
				img = sprites->exit->img[sprites->exit->position];
			render_at(self, img, locs);
		}
	}
}
