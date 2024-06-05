/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:14:49 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 21:39:13 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void	attach(t_vector *arr, t_node *it, t_node *after)
{
	if (after == arr->first)
		arr->first = it;
	if (after->prev)
	{
		after->prev->next = it;
		it->prev = after->prev;
	}
	it->next = after;
	after->prev = it;
}

void	vec_add_at(t_vector *arr, t_node *it, int at)
{
	int		i;
	t_node	*elt;

	if (!arr || !it || at < 0 || at >= vec_size(arr))
		return ;
	i = 0;
	if (node_index_of(arr, it) >= 0)
		arr->size--;
	it = node_detach(arr, it);
	elt = arr->first;
	while (elt && i != at)
	{
		elt = elt->next;
		i++;
	}
	arr->size++;
	if (!elt)
		vec_add(arr, it);
	else
		attach(arr, it, elt);
}
