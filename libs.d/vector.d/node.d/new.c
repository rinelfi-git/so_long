/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:43:45 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 21:15:59 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

t_node	*node_new(void (*destruct)(t_node *))
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->next = 0;
	new->prev = 0;
	new->destruct = destruct;
	return (new);
}
