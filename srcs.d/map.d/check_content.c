/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:54:29 by erijania          #+#    #+#             */
/*   Updated: 2024/07/08 12:15:28 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include "libft.h"
#include <stdlib.h>

static int	write_msg(t_exception *e)
{
	free(e->msg);
	e->msg = ft_strdup("Error\n > Authorized contents are 0, 1, C, E, P");
	return (0);
}

int	check_content(t_map *map, t_exception *ex)
{
	int	location[2];

	location[0] = -1;
	while (++location[0] < map->height)
	{
		location[1] = -1;
		while (++location[1] < map->width)
		{
			if (!ft_strrchr("01CEP", map->data[location[0]][location[1]]))
				return (write_msg(ex));
		}
	}
	return (1);
}
