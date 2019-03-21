/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:04:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/11 13:56:13 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_string_left_align(char *str, t_struct *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->precision_specified && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	f->len += write(f->fd, str, strlen);
	while (f->width > strlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_string_right_align(char *str, t_struct *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->precision_specified && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	while (f->width > strlen)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, str, strlen);
}

void		ft_print_string(char type, t_struct *f, va_list ap)
{
	char	*str;

	if (type == 's')
	{
		str = va_arg(ap, char *);
		if (f->minus)
			ft_print_string_left_align(str, f);
		else
			ft_print_string_right_align(str, f);
	}
}
