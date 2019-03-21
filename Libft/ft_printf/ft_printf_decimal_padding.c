/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_padding.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:48:03 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/13 00:24:58 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding_left_align(int nbrlen, t_struct *f)
{
	while (f->width >= nbrlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

void	ft_padding_right_align(int nbrlen, int n, t_struct *f)
{
	if (f->width > f->precision)
		f->precision = (f->precision < nbrlen) ? nbrlen : f->precision;
	if (!f->precision_specified)
		while (f->width-- > nbrlen)
		{
			if (f->zero)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
		}
	else
	{
		if (f->plus)
			f->width--;
		while (f->width-- > f->precision)
		{
			if ((f->zero && f->width != f->precision) || n == 1)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
		}
	}
}
