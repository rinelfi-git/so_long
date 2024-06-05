/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:15:42 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 21:39:55 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_add(t_vector *self, t_node *n)
{
	t_node	*elt;

	if (!self || !n)
		return (0);
	elt = self->first;
	while (elt != self->last && elt != n)
		elt = elt->next;
	if (elt == n)
		return (0);
	if (!elt)
	{
		self->first = n;
		self->last = n;
	}
	else
	{
		elt->next = n;
		n->prev = elt;
		n->next = 0;
		self->last = n;
	}
	self->size++;
	return (1);
}
