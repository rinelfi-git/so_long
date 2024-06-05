/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:48:25 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 20:52:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

t_vector	*vec_new(t_node *it)
{
	t_vector	*new;

	new = (t_vector *)malloc(sizeof(t_vector));
	if (!new)
		return (0);
	new->first = 0;
	new->last = 0;
	new->size = 0;
	if (it)
	{
		new->first = it;
		new->last = it;
		new->size++;
	}
	return (new);
}
