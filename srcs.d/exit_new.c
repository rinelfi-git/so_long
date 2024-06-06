/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:26:28 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 15:30:23 by erijania         ###   ########.fr       */
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
	new->destruct = exit_destruct;
	return (new);
}
