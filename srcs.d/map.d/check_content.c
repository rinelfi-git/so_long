/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:54:29 by erijania          #+#    #+#             */
/*   Updated: 2024/07/09 09:20:32 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include "libft.h"
#include <stdlib.h>
#define TEMP_STR 29

static int	write_msg(t_exception *e, char c)
{
	char	str[TEMP_STR];

	ft_strlcpy(str, "And 'X' is not one of them.\n", TEMP_STR);
	str[5] = c;
	free(e->msg);
	e->msg = ft_strjoin(
			"Error\n > Authorized contents are 0, 1, C, E, P. ",
			str
			);
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
				return (write_msg(ex, map->data[location[0]][location[1]]));
		}
	}
	return (1);
}
