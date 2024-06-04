/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:20:32 by erijania          #+#    #+#             */
/*   Updated: 2024/03/23 20:55:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(long n)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789";
	if (n > 9)
		i = ft_putnbr(n / 10);
	return (i + ft_printchar(base[n % 10]));
}

int	ft_printint(int n)
{
	int		i;
	long	cast;

	i = 0;
	cast = (long)n;
	if (n < 0)
	{
		cast = -cast;
		i += ft_printchar('-');
	}
	return (i + ft_putnbr(cast));
}
