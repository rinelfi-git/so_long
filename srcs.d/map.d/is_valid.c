/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:40:48 by erijania          #+#    #+#             */
/*   Updated: 2024/07/08 11:54:14 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"

static int	end(t_map *map, int value)
{
	((t_node *)map)->destruct((t_node *)map);
	return (value);
}

int	map_is_valid(char *path, t_exception *ex)
{
	t_map	*map;

	ex->exit_code = 1;
	if (!check_path(path, ex))
		return (0);
	if (!check_extension(path, ex))
		return (0);
	map = map_new(path);
	if (!check_shape(map, ex))
		return (end(map, 0));
	if (!check_content(map, ex))
		return (end(map, 0));
	if (!check_unique(map, ex, 'P', "player\n"))
		return (end(map, 0));
	if (!check_unique(map, ex, 'E', "exit\n"))
		return (end(map, 0));
	if (!check_outlines(map, ex))
		return (end(map, 0));
	if (!check_road(map, ex))
		return (end(map, 0));
	return (end(map, 1));
}
