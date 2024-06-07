/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:08:46 by erijania          #+#    #+#             */
/*   Updated: 2024/06/07 14:19:41 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MANAGER_H
# define WINDOW_MANAGER_H
# include "vector.h"

typedef struct s_frame	t_frame;
struct s_frame
{
	void		*x;
	void		*display;
	t_vector	*components;
};
enum e_xevent
{
	ON_DESTROY = 17
};
t_frame	*frame_init(void);
int		frame_close(t_frame *self);
void	frame_repaint(t_frame *self);
void	frame_open(t_frame *self);
#endif
