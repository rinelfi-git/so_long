/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:33:58 by erijania          #+#    #+#             */
/*   Updated: 2024/06/04 18:09:19 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_WIDTH 34
# define TILE_HEIGHT 34

struct s_environement
{
	char	*img_path;
};
void	player_up(void);
void	player_down(void);
void	player_left(void);
void	player_right(void);
void	exit_open(void);
void	exit_close(void);
#endif
