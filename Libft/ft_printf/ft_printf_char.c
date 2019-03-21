/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:46:07 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/11 21:25:31 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char_left_align(unsigned char c, t_struct *f)
{
	f->len += write(f->fd, &c, 1);
	while (f->width > 1)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_char_right_align(unsigned char c, t_struct *f)
{
	while (f->width > 1)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, &c, 1);
}

void		ft_print_char(char type, t_struct *f, va_list ap)
{
	unsigned char	c;

	if (type == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		if (f->minus)
			ft_print_char_left_align(c, f);
		else
			ft_print_char_right_align(c, f);
	}
}
