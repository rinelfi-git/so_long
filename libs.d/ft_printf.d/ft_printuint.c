/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:49:58 by erijania          #+#    #+#             */
/*   Updated: 2024/03/23 20:43:48 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int n)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789";
	if (n > 9)
		i = ft_printuint(n / 10);
	return (i + ft_printchar(base[n % 10]));
}
