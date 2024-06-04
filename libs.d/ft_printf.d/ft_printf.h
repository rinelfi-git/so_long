/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:02:31 by erijania          #+#    #+#             */
/*   Updated: 2024/03/23 21:30:56 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printint(int n);
int	ft_printuint(unsigned int n);
int	ft_printhex(unsigned long n, char id);
int	ft_printpointer(void *p);
#endif