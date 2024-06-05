/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:37:26 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 21:38:53 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_node	*node_detach(t_vector *self, t_node *n)
{
	if (!n)
		return (0);
	if (self->first == n)
		self->first = n->next;
	if (self->last == n)
		self->last = n->prev;
	if (n->prev)
		n->prev->next = n->next;
	if (n->next)
		n->next->prev = n->prev;
	n->next = 0;
	n->prev = 0;
	return (n);
}
