/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:37:47 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 10:44:08 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

static t_node	*long_clone(t_node *self)
{
	t_long_node	*clone;
	t_long_node	*cast;

	if (!self)
		return (0);
	cast = (t_long_node *)self;
	clone = long_new(cast->value);
	return ((t_node *)clone);
}

static void	long_destruct(t_node *self)
{
	free(self);
}

t_long_node	*long_new(long value)
{
	t_long_node	*new;

	new = (t_long_node *) malloc(sizeof(t_long_node));
	if (!new)
		exit (1);
	new->value = value;
	new->node.prev = 0;
	new->node.next = 0;
	new->node.clone = long_clone;
	new->node.destruct = long_destruct;
	return (new);
}
