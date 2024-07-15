/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:56:28 by erijania          #+#    #+#             */
/*   Updated: 2024/07/15 11:15:44 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window_manager.h"
#include "so_long.h"
#include "ft_printf.h"
#include <X11/keysym.h>

int	handle_key(int keysim, t_frame *frame)
{
	t_map		*map;
	t_sprites	*sprites;
	int			locs[2];

	locs[0] = 0;
	locs[1] = 0;
	if (keysim == XK_Escape)
		return (frame_close(frame));
	map = (t_map *)node_get(frame->components, 0);
	sprites = (t_sprites *)node_get(frame->components, 1);
	element_locate('P', map, locs);
	if (locs[0] == -1 && locs[1] == -1)
		return (frame_close(frame));
	if (keysim == XK_z)
		player_up(sprites, map);
	else if (keysim == XK_d)
		player_right(sprites, map);
	else if (keysim == XK_s)
		player_down(sprites, map);
	else if (keysim == XK_q)
		player_left(sprites, map);
	frame_repaint(frame);
	return (0);
}

void	frame_open(t_frame *self)
{
	t_map	*map;

	map = (t_map *)node_get(self->components, 0);
	self->display = mlx_new_window(self->x,
			TILE_WIDTH * map->width, TILE_HEIGHT * map->height, "./so_long");
	frame_repaint(self);
	mlx_hook(self->display, ON_DESTROY, 0L, frame_close, self);
	mlx_key_hook(self->display, handle_key, self);
	mlx_loop(self->x);
}
