/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:25:34 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 22:11:58 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vec_filter(t_vector *src, int (*eval)(int, t_node *))
{
	t_vector	*filtered;
	t_node		*loop;
	int			i;

	if (!src)
		return (0);
	filtered = vec_new(0);
	loop = src->first;
	i = 0;
	while (loop)
	{
		if (eval(i++, loop))
			vec_add(filtered, loop->clone(loop));
		loop = loop->next;
	}
	return (filtered);
}
