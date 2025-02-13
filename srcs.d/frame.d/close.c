/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:19:52 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 13:38:45 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manager.h"
#include "mlx.h"
#include <stdlib.h>

int	frame_close(t_frame *self)
{
	if (!self || !self->x)
		return (1);
	vec_destruct(self->components);
	if (self->display)
		mlx_destroy_window(self->x, self->display);
	mlx_destroy_display(self->x);
	free(self->x);
	free(self);
	exit(0);
	return (0);
}
