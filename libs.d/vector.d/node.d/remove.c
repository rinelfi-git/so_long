/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:57:47 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 21:53:06 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static t_node	*remove_asc(t_vector *self, int index)
{
	int		i;
	t_node	*loop;

	i = 0;
	loop = self->first;
	while (loop && i != index)
	{
		loop = loop->next;
		i++;
	}
	if (i != index)
		return (0);
	self->size--;
	return (node_detach(self, loop));
}

static t_node	*remove_desc(t_vector *self, int index)
{
	int		i;
	t_node	*loop;

	i = -1;
	loop = self->last;
	while (loop && i != index)
	{
		loop = loop->next;
		i--;
	}
	if (i != index)
		return (0);
	self->size--;
	return (node_detach(self, loop));
}

t_node	*node_remove(t_vector *self, int index)
{
	if (!self)
		return (0);
	if (index >= 0)
		return (remove_asc(self, index));
	return (remove_desc(self, index));
}
