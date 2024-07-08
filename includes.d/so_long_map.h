/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:08:22 by erijania          #+#    #+#             */
/*   Updated: 2024/07/08 09:37:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAP_H
# define SO_LONG_MAP_H
# include "so_long.h"
# include "libft.h"

int  check_unique(t_map *map, t_exception *e, char thing, const char *desc);
int  check_shape(t_map *map, t_exception *e);
int	check_outlines(t_map *map, t_exception *e);
int	check_road(t_map *map, t_exception *e);
int	check_extension(t_map *map);
#endif