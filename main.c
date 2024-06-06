/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:12 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 21:26:55 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window_manager.h"
#include "ft_printf.h"
#include <X11/keysym.h>
#include <fcntl.h>

int	handle_key(int keysim, t_frame *frame)
{
	t_map		*map;
	t_sprites	*sprites;
	int			locations[2];

	locations[0] = 0;
	locations[1] = 0;
	if (keysim == XK_Escape)
		return (frame_close(frame));
	map = (t_map *)node_get(frame->components, 0);
	sprites = (t_sprites *)node_get(frame->components, 1);
	if (keysim == XK_z)
		player_up(sprites, map);
	else if (keysim == XK_d)
		player_right(sprites, map);
	else if (keysim == XK_s)
		player_down(sprites, map);
	else if (keysim == XK_q)
		player_left(sprites, map);
	player_locate(map, locations);
	if (locations[0] == -1 && locations[1] == -1)
		return (frame_close(frame));
	frame_repaint(frame, map, sprites);
	return (0);
}

int	main(void)
{
	t_frame		*frame;
	t_map		*map;
	t_sprites	*sprites;

	frame = frame_create();
	map = map_new(open("./assets.d/map.d/correct.ber", O_RDONLY));
	sprites = sprites_init(frame->x);
	vec_add(frame->components, (t_node *) map);
	vec_add(frame->components, (t_node *) sprites);
	frame->display = mlx_new_window(frame->x,
			TILE_WIDTH * map->width, TILE_HEIGHT * map->height, "So long");
	frame_repaint(frame, map, sprites);
	mlx_hook(frame->display, ON_DESTROY, 0L, frame_close, frame);
	mlx_key_hook(frame->display, handle_key, frame);
	mlx_loop(frame->x);
	return (0);
}
