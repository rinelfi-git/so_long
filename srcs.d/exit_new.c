/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:26:28 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 20:53:26 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	exit_destruct(t_exit *self, void *x)
{
	int	i;

	i = -1;
	while (++i < 6)
		self->img[i]->destruct(self->img[i], x);
	free(self);
}

t_exit	*exit_new(void *x)
{
	t_exit	*new;

	new = (t_exit *)malloc(sizeof(t_exit));
	new->position = 0;
	new->img[0] = img_new("exit-close.xpm", x);
	new->img[1] = img_new("exit-open.xpm", x);
	new->img[2] = img_new("exit-up.xpm", x);
	new->img[3] = img_new("exit-right.xpm", x);
	new->img[4] = img_new("exit-down.xpm", x);
	new->img[5] = img_new("exit-left.xpm", x);
	new->destruct = exit_destruct;
	return (new);
}
