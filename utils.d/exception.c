/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:44:54 by erijania          #+#    #+#             */
/*   Updated: 2024/07/11 11:19:51 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

t_exception	*ex_new(const char *msg, int exit_code)
{
	t_exception	*new;

	new = (t_exception *)malloc(sizeof(t_exception));
	if (!new)
		exit(1);
	new->component.next = 0;
	new->component.prev = 0;
	new->component.destruct = ex_free;
	if (msg)
		new->msg = ft_strdup(msg);
	new->exit_code = exit_code;
	return (new);
}

void	ex_free(t_node *e)
{
	t_exception	*cast;

	cast = (t_exception *)e;
	if (!cast)
		return ;
	if (cast->msg)
		free(cast->msg);
	free(e);
}

int	ex_die(t_exception *e)
{
	int	exit_code;

	if (!e)
		return (1);
	ft_printstr(e->msg);
	exit_code = e->exit_code;
	ex_free((t_node *)e);
	return (exit_code);
}
