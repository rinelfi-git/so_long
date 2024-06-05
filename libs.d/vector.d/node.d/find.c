/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:56:46 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 21:25:14 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_node	*node_find(t_vector *self, int (*eval)(int, t_node *))
{
	t_node	*found;
	int		index;

	if (!self || !self->first)
		return (0);
	found = self->first;
	index = 0;
	while (found && !eval(index++, found))
		found = found->next;
	return (found);
}
