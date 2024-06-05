/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 06:58:18 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 20:52:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	vec_destruct(t_vector *arr)
{
	t_node	*elt;

	if (!arr)
		return ;
	elt = node_remove(arr, 0);
	while (elt)
	{
		if (elt->destruct)
			elt->destruct(elt);
		elt = node_remove(arr, 0);
	}
	free(arr);
	arr = 0;
}
