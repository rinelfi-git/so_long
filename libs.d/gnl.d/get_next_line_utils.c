/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:51:09 by erijania          #+#    #+#             */
/*   Updated: 2024/06/06 12:11:55 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_seek(char *s)
{
	size_t	c;

	c = 0;
	while (c < BUFFER_SIZE && s[c])
	{
		if (s[c++] == '\n')
			break ;
	}
	return (c);
}

char	*fill(char *str, char *buffer, size_t seek)
{
	char	*ret;
	char	*str_join;
	size_t	i;

	ret = (char *)malloc((seek + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < seek)
		ret[i++] = *(buffer++);
	ret[i] = '\0';
	if (!str || ft_strlen(str) == 0)
		return (ret);
	str_join = ft_strjoin(str, ret);
	free(str);
	free(ret);
	if (!str_join)
		return (NULL);
	ret = str_join;
	return (ret);
}

void	clean_left(char *buff, size_t seek)
{
	size_t	i;

	i = seek;
	while (i < BUFFER_SIZE)
	{
		buff[i - seek] = buff[i];
		i++;
	}
	i = BUFFER_SIZE - seek;
	while (i < BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
}
