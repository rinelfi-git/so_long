/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:37:47 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 10:44:09 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

static t_node	*int_clone(t_node *self)
{
	t_int_node	*clone;
	t_int_node	*cast;

	if (!self)
		return (0);
	cast = (t_int_node *)self;
	clone = int_new(cast->value);
	return ((t_node *)clone);
}

static void	int_destruct(t_node *self)
{
	free(self);
}

t_int_node	*int_new(int value)
{
	t_int_node	*new;

	new = (t_int_node *) malloc(sizeof(t_int_node));
	if (!new)
		exit (1);
	new->value = value;
	new->node.prev = 0;
	new->node.next = 0;
	new->node.clone = int_clone;
	new->node.destruct = int_destruct;
	return (new);
}
