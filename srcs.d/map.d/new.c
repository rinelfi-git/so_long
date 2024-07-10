/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:55:42 by erijania          #+#    #+#             */
/*   Updated: 2024/07/10 23:11:04 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "vector.h"
#include "libft.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	map_destruct(t_node *self)
{
	t_map	*cast;
	int		i;

	cast = (t_map *)self;
	i = -1;
	while (++i < cast->height)
		free(cast->data[i]);
	free(cast->path);
	free(cast->data);
	free(cast);
}

static void	parse_list(int fd, t_vector *vect)
{
	t_str_node	*string;
	char		*str;

	str = get_next_line(fd);
	while (str && ft_strlen(str))
	{
		string = str_new(str);
		free(str);
		if (ft_strchr(string->value, '\n'))
		{
			str = ft_substr(string->value, 0, ft_strlen(string->value) - 1);
			free(string->value);
			string->value = str;
		}
		vec_add(vect, (t_node *)string);
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
}

static char	**string_tab_from_list(t_vector *vect)
{
	char	**string_tab;
	t_node	*node;
	int		i;

	string_tab = (char **)malloc(sizeof(char *) * vec_size(vect));
	if (!string_tab)
		exit (1);
	node = vect->first;
	i = 0;
	while (node)
	{
		string_tab[i++] = ft_strdup(((t_str_node *)node)->value);
		node = node->next;
	}
	vec_destruct(vect);
	return (string_tab);
}

t_map	*map_new(const char *path)
{
	t_map		*new;
	t_vector	*list;
	int			fd;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		exit (1);
	list = vec_new(0);
	new->path = ft_strdup(path);
	fd = open(new->path, O_RDONLY);
	new->component.next = 0;
	new->component.prev = 0;
	new->component.destruct = map_destruct;
	parse_list(fd, list);
	new->height = vec_size(list);
	new->data = string_tab_from_list(list);
	new->width = 0;
	if (new->height > 0)
		new->width = ft_strlen(new->data[0]);
	close(fd);
	return (new);
}
