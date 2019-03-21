/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:28:14 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/19 12:28:22 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_float_left(char *str, t_struct *f)
{
	int		i;

	i = ft_strlen(str);
	f->len += write(f->fd, str, i);
	while (i < f->width)
	{
		f->len += write(f->fd, " ", 1);
		i++;
	}
}

static void	ft_print_float_right(char *str, t_struct *f)
{
	int		i;

	i = ft_strlen(str);
	while (f->width > i)
	{
		if (f->zero)
		{
			f->len += write(f->fd, "0", 1);
			i++;
		}
		else
		{
			f->len += write(f->fd, " ", 1);
			i++;
		}
	}
	f->len += write(f->fd, str, ft_strlen(str));
}

void		ft_print_float(char type, t_struct *f, va_list ap)
{
	long double		dbl;
	char			*str;

	if (f->length == 7 || type == 'F')
		dbl = va_arg(ap, double);
	else if (f->length == L || type == 'f')
		dbl = va_arg(ap, double);
	else
	{
		f->len = -1;
		return ;
	}
	if (!f->precision_specified)
		f->precision = 6;
	str = ft_ldtoa(dbl, f->precision);
	if (f->minus)
		ft_print_float_left(str, f);
	else
		ft_print_float_right(str, f);
	free(str);
}
