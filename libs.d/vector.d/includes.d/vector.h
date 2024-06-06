/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:26:03 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 10:45:23 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector		t_vector;
typedef struct s_node		t_node;
typedef struct s_char_node	t_char_node;
typedef struct s_str_node	t_str_node;
typedef struct s_int_node	t_int_node;
typedef struct s_long_node	t_long_node;
struct s_node
{
	t_node	*prev;
	t_node	*next;
	t_node	*(*clone)(t_node *);
	void	(*destruct)(t_node *);
};
struct s_vector
{
	t_node	node;
	int		size;
	t_node	*first;
	t_node	*last;
};
struct s_char_node
{
	t_node	node;
	char	value;
};
struct s_str_node
{
	t_node	node;
	char	*value;
};
struct s_int_node
{
	t_node	node;
	int		value;
};
struct s_long_node
{
	t_node	node;
	long	value;
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
t_char_node	*char_new(char value);
t_int_node	*int_new(int value);
t_long_node	*long_new(long value);
t_str_node	*str_new(const char *value);
#endif