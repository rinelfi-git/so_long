/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:20:32 by rinelfi           #+#    #+#             */
/*   Updated: 2024/03/23 20:16:15 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;

	if (!s)
		return (ft_printstr("(null)"));
	i = 0;
	while (s[i])
		ft_printchar(s[i++]);
	return (i);
}
