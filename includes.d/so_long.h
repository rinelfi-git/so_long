/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:33:58 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 22:58:45 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_WIDTH 34
# define TILE_HEIGHT 34

typedef struct s_img	t_img;
typedef struct s_player	t_player;
struct s_img
{
	char	*path;
	void	*img;
};
struct s_player
{
	t_img	*img_up[4];
};
t_player	*player_new(void *x);
void		player_up(void);
void		player_down(void);
void		player_left(void);
void		player_right(void);
t_img		*img_new(const char *name, void *x);
void		exit_open(void);
void		exit_close(void);
#endif
