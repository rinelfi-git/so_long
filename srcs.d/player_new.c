/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:26:56 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 22:59:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

t_player	*player_new(void *x)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	if (!new)
		return (0);
	new->img_up[0] = img_new("mario-w.xpm", x);
	new->img_up[1] = img_new("mario-d.xpm", x);
	new->img_up[2] = img_new("mario-s.xpm", x);
	new->img_up[3] = img_new("mario-a.xpm", x);
	return (new);
}
