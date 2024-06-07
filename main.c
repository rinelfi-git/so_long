/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:12 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 16:26:18 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manager.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_frame		*frame;
	t_map		*map;
	t_sprites	*sprites;
	t_exception	*ex;

	ex = ex_new("Error\n > Number of argument incorrect !\n", 1);
	if (argc != 2)
		return (ex_die(ex));
	map = map_new(argv[1]);
	if (!map_is_valid(map, ex))
	{
		((t_node *)map)->destruct((t_node *)map);
		return (ex_die(ex));
	}
	frame = frame_init();
	sprites = sprites_init(frame->x);
	vec_add(frame->components, (t_node *) map);
	vec_add(frame->components, (t_node *) sprites);
	vec_add(frame->components, (t_node *) ex);
	frame_open(frame);
	return (0);
}
