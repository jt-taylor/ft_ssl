/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:46:15 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/12 23:54:56 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == 'd' || format[f->i] == 'i' || format[f->i] == 'D')
		ft_print_decimal(format[f->i], f, ap);
	else if (format[f->i] == 'o' || format[f->i] == 'O')
		ft_print_octal(format[f->i], f, ap);
	else if (format[f->i] == 'u' || format[f->i] == 'U')
		ft_print_unsigned_decimal(format[f->i], f, ap);
	else if (format[f->i] == 'x' || format[f->i] == 'X')
		ft_print_hex(format[f->i], f, ap);
	else if (format[f->i] == 'p')
		ft_print_pointer(format[f->i], f, ap);
	else if (format[f->i] == 'b')
		ft_print_binary(format[f->i], f, ap);
	else if (format[f->i] == 'c')
		ft_print_char(format[f->i], f, ap);
	else if (format[f->i] == 's')
		ft_print_string(format[f->i], f, ap);
	else if (format[f->i] == '%')
		ft_print_percent_sign(format[f->i], f);
	else if (format[f->i] == 'f' || format[f->i] == 'F')
		ft_print_float(format[f->i], f, ap);
}

static void		ft_reset_struct(t_struct *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->width = 0;
	f->precision_specified = 0;
	f->precision = 0;
	f->length = 0;
}

void			ft_process_string(const char *format, t_struct *f, va_list ap)
{
	while (format[f->i] != '\0')
	{
		if (format[f->i] == '%')
		{
			f->i++;
			if (ft_strchr("#-+ .*0123456789hljzL", format[f->i]))
				ft_parse_modifiers(format, f, ap);
			if (ft_strchr("spdDioOuUxXcfFb%", format[f->i]))
			{
				ft_print(format, f, ap);
				if (f->len == -1)
					return ;
				ft_reset_struct(f);
			}
		}
		else
			f->len += write(f->fd, &format[f->i], 1);
		f->i++;
	}
}
