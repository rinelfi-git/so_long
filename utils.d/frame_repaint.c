/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_repaint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:48:13 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 20:42:48 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manager.h"
#include "mlx.h"

static void	render_at(t_frame *frame, t_img *img, int x, int y)
{
	mlx_put_image_to_window(frame->x,
		frame->display,
		img->img,
		TILE_WIDTH * x,
		TILE_HEIGHT * y);
}

void	frame_repaint(t_frame *self, t_map *map, t_sprites *sprites)
{
	int		x;
	int		y;
	t_img	*img;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			img = sprites->floor;
			if (map->data[y][x] == '1')
				img = sprites->wall;
			else if (map->data[y][x] == 'P')
				img = sprites->player->img[sprites->player->position];
			else if (map->data[y][x] == 'C')
				img = sprites->collectible;
			else if (map->data[y][x] == 'E')
				img = sprites->exit->img[sprites->exit->position];
			render_at(self, sprites->floor, x, y);
			render_at(self, img, x, y);
			x++;
		}
		y++;
	}
}
