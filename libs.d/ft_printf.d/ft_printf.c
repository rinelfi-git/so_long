/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:03:17 by erijania          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:44 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(va_list va, char id)
{
	if (id == 'c')
		return (ft_printchar((char)va_arg(va, int)));
	if (id == 's')
		return (ft_printstr(va_arg(va, char *)));
	if (id == 'd' || id == 'i')
		return (ft_printint(va_arg(va, int)));
	if (id == 'u')
		return (ft_printuint(va_arg(va, unsigned int)));
	if (id == 'x' || id == 'X')
		return (ft_printhex(va_arg(va, unsigned int), id));
	if (id == 'p')
		return (ft_printpointer(va_arg(va, void *)));
	return (ft_printchar('%'));
}

int	ft_printf(const char *s, ...)
{
	int		ret;
	va_list	args;

	va_start(args, s);
	ret = 0;
	while (*s)
	{
		if (*s++ == '%')
			ret += ft_print_format(args, *(s++));
		else
			ret += ft_printchar(*(s - 1));
	}
	va_end(args);
	return (ret);
}
