/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:33:58 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 15:20:51 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_WIDTH 34
# define TILE_HEIGHT 34
# include "vector.h"
# include "ft_printf.h"

typedef struct s_img		t_img;
typedef struct s_player		t_player;
typedef struct s_exit		t_exit;
typedef struct s_sprites	t_sprites;
typedef struct s_map		t_map;
typedef struct s_string		t_string;
struct s_img
{
	char	*path;
	void	*img;
	void	(*destruct)(t_img *, void *);
};
struct s_player
{
	t_img	*img[4];
	int		position;
	int		move;
	void	(*destruct)(t_player *, void *);
};
struct s_exit
{
	t_img	*img[6];
	int		position;
	void	(*destruct)(t_player *, void *);
};
struct s_sprites
{
	t_node		componemt;
	void		*x;
	t_img		*wall;
	t_img		*floor;
	t_img		*collectible;
	t_player	*player;
	t_exit		*exit;
};
struct s_map
{
	t_node	componemt;
	int		width;
	int		height;
	char	**data;
};
struct s_string
{
	t_node	parent;
	char	*val;
};
t_player	*player_new(void *x);
t_exit		*exit_new(void *x);
t_map		*map_new(int fd);
t_sprites	*sprites_init(void *x);
void		player_up(t_player *player, t_map *map);
void		player_down(t_player *player, t_map *map);
void		player_left(t_player *player, t_map *map);
void		player_right(t_player *player, t_map *map);
t_img		*img_new(const char *name, void *x);
void		exit_open(void);
void		exit_close(void);
#endif
