/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:08:46 by erijania          #+#    #+#             */
/*   Updated: 2024/06/04 21:14:44 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MANAGER_H
# define WINDOW_MANAGER_H

typedef struct s_frame	t_frame;
struct s_frame
{
	void	*x;
	void	*display;
};
enum e_xevent
{
	ON_DESTROY = 17
};
t_frame	*frame_create(void);
int		frame_close(t_frame *self);
#endif
