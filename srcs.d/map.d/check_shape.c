/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:11:19 by erijania          #+#    #+#             */
/*   Updated: 2024/07/09 09:11:06 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include <stdlib.h>

int	check_shape(t_map *map, t_exception *e)
{
	int	y;
	int	length;

	y = 0;
	length = ft_strlen(map->data[y]);
	while (y < map->height)
	{
		if (length != (int)ft_strlen(map->data[y]))
		{
			free(e->msg);
			e->msg = ft_strjoin(
					"Error\n > ",
					"You have choice between square or rectangle form.\n"
					);
			return (0);
		}
		y++;
	}
	return (1);
}
