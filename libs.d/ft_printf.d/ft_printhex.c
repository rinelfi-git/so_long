/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:56:27 by erijania          #+#    #+#             */
/*   Updated: 2024/03/23 21:25:25 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long n, char id)
{
	char	*bases[2];
	int		i;

	bases[0] = "0123456789abcdef";
	bases[1] = "0123456789ABCDEF";
	i = 0;
	if (n > 15)
		i = ft_printhex(n / 16, id);
	return (i + ft_printchar(bases[id == 'X'][n % 16]));
}
