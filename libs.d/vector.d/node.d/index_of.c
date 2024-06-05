/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:33:46 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 20:52:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	node_index_of(t_vector *arr, t_node *it)
{
	int		i;
	t_node	*loop;

	if (!arr || !it)
		return (-1);
	i = 0;
	loop = arr->first;
	while (loop && loop != it)
	{
		loop = loop->next;
		i++;
	}
	if (loop == it)
		return (i);
	return (-1);
}
