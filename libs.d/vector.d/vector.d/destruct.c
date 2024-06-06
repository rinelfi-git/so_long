/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 06:58:18 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 10:16:36 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	vec_destruct(t_vector *self)
{
	t_node	*elt;

	if (!self)
		return ;
	elt = node_remove(self, 0);
	while (elt)
	{
		if (elt->destruct)
			elt->destruct(elt);
		elt = node_remove(self, 0);
	}
	free(self);
	self = 0;
}
