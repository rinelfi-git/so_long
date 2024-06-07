/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:08:06 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 14:19:42 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manager.h"
#include "mlx.h"
#include <stdlib.h>

t_frame	*frame_init(void)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (!frame)
		return (0);
	frame->x = mlx_init();
	frame->display = 0;
	frame->components = vec_new(0);
	return (frame);
}
