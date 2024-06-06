/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:29:07 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 12:48:12 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (length);
	while (*(str++))
		length++;
	return (length);
}

static char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		exit(1);
	i = -1;
	while (str && str[++i])
		dup[i] = str[i];
	dup[i] = 0;
	return (dup);
}

static t_node	*str_clone(t_node *self)
{
	t_str_node	*clone;
	t_str_node	*cast;

	if (!self)
		return (0);
	cast = (t_str_node *)self;
	clone = str_new(cast->value);
	return ((t_node *)clone);
}

static void	str_destruct(t_node *self)
{
	t_str_node	*cast;

	cast = (t_str_node *)self;
	free(cast->value);
	free(cast);
}

t_str_node	*str_new(const char *value)
{
	t_str_node	*new;

	new = (t_str_node *)malloc(sizeof(t_str_node));
	if (!new)
		exit (1);
	new->value = ft_strdup(value);
	new->node.prev = 0;
	new->node.next = 0;
	new->node.clone = str_clone;
	new->node.destruct = str_destruct;
	return (new);
}
