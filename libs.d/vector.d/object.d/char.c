/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:05:55 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 10:43:53 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

static t_node	*char_clone(t_node *self)
{
	t_char_node	*clone;
	t_char_node	*cast;

	if (!self)
		return (0);
	cast = (t_char_node *)self;
	clone = char_new(cast->value);
	return ((t_node *)clone);
}

static void	char_destruct(t_node *self)
{
	free(self);
}

t_char_node	*char_new(char value)
{
	t_char_node	*new;

	new = (t_char_node *) malloc(sizeof(t_char_node));
	if (!new)
		exit (1);
	new->value = value;
	new->node.prev = 0;
	new->node.next = 0;
	new->node.clone = char_clone;
	new->node.destruct = char_destruct;
	return (new);
}
