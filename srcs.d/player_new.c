/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:26:56 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 14:43:11 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static void img_free(t_img *img, void *x)
{
	free(img->path);
	mlx_destroy_image(x, img->img);
	free(img);
}

static void player_dsetruct(t_player *player, void *x)
{
	img_free(player->img[0], x);
	img_free(player->img[1], x);
	img_free(player->img[2], x);
	img_free(player->img[3], x);
	free(player);
}

t_player	*player_new(void *x)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	if (!new)
		return (0);
	new->move = 0;
	new->position = 2;
	new->destruct = player_dsetruct;
	new->img[0] = img_new("mario-w.xpm", x);
	new->img[1] = img_new("mario-d.xpm", x);
	new->img[2] = img_new("mario-s.xpm", x);
	new->img[3] = img_new("mario-a.xpm", x);
	return (new);
}
