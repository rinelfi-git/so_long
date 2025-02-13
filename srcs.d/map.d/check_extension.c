/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:37:33 by erijania          #+#    #+#             */
/*   Updated: 2024/07/09 09:09:07 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

static int	split_count(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static char	*str_to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'a' + (str[i] - 'A');
		i++;
	}
	return (str);
}

int	check_extension(char *path, t_exception *e)
{
	char	**splited;
	char	*extension;
	char	valid;
	int		i;

	extension = 0;
	splited = ft_split(path, '.');
	if (split_count(splited) > 0)
		extension = str_to_lower(splited[split_count(splited) - 1]);
	valid = extension && ft_strncmp(extension, "ber", 3) == 0;
	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
	if (!valid)
	{
		free(e->msg);
		e->msg = ft_strjoin(
				"Error\n > ",
				"I don't recognize this file extension. Only [.ber].\n"
				);
	}
	return (valid);
}
