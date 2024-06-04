/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:42:12 by erijania          #+#    #+#             */
/*   Updated: 2024/06/04 21:17:26 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window_manager.h"
#include <X11/keysym.h>

int	handle_key(int keysim, t_frame *frame)
{
	if (keysim == XK_Escape)
		return (frame_close(frame));
	return (0);
}

int	main(void)
{
	t_frame	*frame;

	frame = frame_create();
	frame->display = mlx_new_window(frame->x, 800, 640, "So long");
	mlx_hook(frame->display, ON_DESTROY, 0L, frame_close, frame);
	mlx_key_hook(frame->display, handle_key, frame);
	mlx_loop(frame->x);
	return (0);
}
