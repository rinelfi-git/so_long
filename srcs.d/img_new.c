/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:29:08 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 20:53:37 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

static void	img_free(t_img *img, void *x)
{
	free(img->path);
	mlx_destroy_image(x, img->img);
	free(img);
}

t_img	*img_new(const char *name, void *x)
{
	t_img	*new;
	int		sizes[2];

	new = (t_img *)malloc(sizeof(t_img));
	if (!new)
		exit (1);
	new->path = ft_strjoin("./assets.d/img.d/", name);
	new->img = mlx_xpm_file_to_image(x, new->path, sizes, sizes + 1);
	new->destruct = img_free;
	return (new);
}
