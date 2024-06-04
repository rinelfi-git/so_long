/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:22:11 by erijania          #+#    #+#             */
/*   Updated: 2024/03/23 20:54:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *p)
{
	if (!p)
		return (ft_printstr("(nil)"));
	return (ft_printstr("0x") + ft_printhex((long)p, 'x'));
}
