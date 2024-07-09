/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:12 by erijania          #+#    #+#             */
/*   Updated: 2024/07/09 09:05:51 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manager.h"
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_frame		*frame;
	t_map		*map;
	t_sprites	*sprites;
	t_exception	*ex;

	ex = ex_new("Error\n > Where is the map ?\n", 1);
	if (argc != 2)
		return (ex_die(ex));
	if (!map_is_valid(argv[1], ex))
		return (ex_die(ex));
	map = map_new(argv[1]);
	frame = frame_init();
	sprites = sprites_init(frame->x);
	vec_add(frame->components, (t_node *) map);
	vec_add(frame->components, (t_node *) sprites);
	vec_add(frame->components, (t_node *) ex);
	frame_open(frame);
	return (0);
}
