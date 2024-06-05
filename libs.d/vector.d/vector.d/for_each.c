/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:10:44 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 21:04:30 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_for_each(t_vector *arr, void (*func)(int, t_node *))
{
	t_node	*loop;
	int		i;

	loop = arr->first;
	i = 0;
	while (loop)
	{
		func(i++, loop);
		loop = loop->next;
	}
}
