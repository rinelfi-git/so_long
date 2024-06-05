/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:26:03 by erijania          #+#    #+#             */
/*   Updated: 2024/06/05 22:00:20 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector		t_vector;
typedef struct s_node		t_node;
struct s_vector
{
	int		size;
	t_node	*first;
	t_node	*last;
};
struct s_node
{
	t_node	*prev;
	t_node	*next;
	t_node	*(*clone)(t_node *);
	void	(*destruct)(t_node *);
};
t_vector	*vec_new(t_node *n);
t_node		*node_new(void (*destruct)(t_node *));
int			vec_size(t_vector *self);
int			node_index_of(t_vector *self, t_node *n);
int			vec_add(t_vector *self, t_node *n);
void		vec_add_at(t_vector *self, t_node *n, int at);
t_node		*node_get(t_vector *self, int index);
t_node		*node_remove(t_vector *self, int index);
void		vec_destruct(t_vector *self);
void		vec_for_each(t_vector *self, void (*iter)(int, t_node *));
t_node		*node_find(t_vector *self, int (*eval)(int, t_node *));
t_vector	*vec_filter(t_vector *self, int (*eval)(int, t_node *));
t_node		*node_detach(t_vector *self, t_node *n);
#endif