/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:26:56 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 15:24:41 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static void destruct(t_player *self, void *x)
{
	int	i;
	
	i = -1;
	while (++i < 4)
		self->img[i]->destruct(self->img[i], x);
	free(self);
}

t_player	*player_new(void *x)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	if (!new)
		return (0);
	new->move = 0;
	new->position = 2;
	new->destruct = destruct;
	new->img[0] = img_new("mario-w.xpm", x);
	new->img[1] = img_new("mario-d.xpm", x);
	new->img[2] = img_new("mario-s.xpm", x);
	new->img[3] = img_new("mario-a.xpm", x);
	return (new);
}
