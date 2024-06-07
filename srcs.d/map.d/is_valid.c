/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:40:48 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 13:25:22 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"

int map_is_valid(t_map *map, t_exception *ex)
{
    ex->exit_code = 1;
	if (!check_shape(map, ex))
		return (0);
    else if (!check_unique(map, ex, 'P', "player\n"))
        return (0);
    else if (!check_unique(map, ex, 'E', "exit\n"))
        return (0);
	else if (!check_outlines(map, ex))
		return (0);
	else if (!check_road(map, ex))
		return (0);
	else
    return (1);
}
