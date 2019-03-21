/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:28:04 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/19 12:28:18 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	%[flags][min field width][precision][length]conversion specifier
**	  -----  ---------------  ---------  ------ -----------------
**	\             #,*        .#, .*     /             \
**	\                                 /               \
**	#,0,-,+, ,',I                 hh,h,l,ll,j,z,L    c,d,u,x,X,e,f,g,s,p,%
**	-------------                 ---------------    -----------------------
**	# | Alternate,                 hh | char,           c | unsigned char,
**	0 | zero pad,                   h | short,          d | signed int,
**	- | left align,                 l | long,           u | unsigned int,
**	+ | explicit + - sign,         ll | long long,      x | unsigned hex int,
**	| space for + sign,           j | [u]intmax_t,    X | unsigned HEX int,
**	' | locale thousands grouping,  z | size_t,         e | [-]d.ddde±dd double,
**	I | Use locale's alt digits     t | ptrdiff_t,      E | [-]d.dddE±dd double,
**	                                   L | long double,  ---------=====
**	if no precision   => 6 decimal places            /  f | [-]d.ddd double,
**	if precision = 0  => 0 decimal places      _____/   g | e|f as appropriate,
**	if precision = #  => # decimal places               G | E|F as appropriate,
**	if flag = #       => always show decimal point      s | string,
**	                                             ..............------
**	                                            /          p | pointer,
**	   if precision      => max field width    /           % | %
*/

/*
** to do list :
** 				fix the right padding for hex and octal float should be fine (?)
*/

static t_struct	*ft_init_struct(t_struct *f)
{
	if ((f = (t_struct*)ft_memalloc(sizeof(t_struct))) == NULL)
		return (NULL);
	f->i = 0;
	f->len = 0;
	return (f);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	int			len;
	t_struct	*f;
	va_list		ap;

	f = NULL;
	if ((f = ft_init_struct(f)) == NULL)
		return (-1);
	f->fd = fd;
	va_start(ap, format);
	if (format[0] == '%' && format[1] == '\0')
		;
	else if (!ft_strchr(format, '%'))
		f->len += write(f->fd, format, ft_strlen(format));
	else
		ft_process_string(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int			len;
	t_struct	*f;
	va_list		ap;

	f = NULL;
	if ((f = ft_init_struct(f)) == NULL)
		return (-1);
	f->fd = 1;
	va_start(ap, format);
	if (format[0] == '%' && format[1] == '\0')
		;
	else if (!ft_strchr(format, '%'))
		f->len += write(f->fd, format, ft_strlen(format));
	else
		ft_process_string(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}
