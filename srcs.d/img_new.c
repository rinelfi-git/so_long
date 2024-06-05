/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:29:08 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 22:57:58 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

t_img	*img_new(const char *name, void *x)
{
	t_img	*new;

	new = (t_img *)malloc(sizeof(t_img));
	if (!new)
		return (0);
	new->path = ft_strjoin(ft_strdup("./assets.d/img.d/"), ft_strdup(name));
	new->img = mlx_xpm_file_to_image(x, new->path, TILE_WIDTH, TILE_HEIGHT);
	return (new);
}
