/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:02:40 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/11 14:33:55 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_itoa_base_pf(int fd, intmax_t value, int base)
{
	int			len;
	intmax_t	value2;
	char		*radix;
	char		*result;

	len = 1;
	value2 = value;
	if (value < -9223372036854775807)
		return (write(fd, "9223372036854775808", 19));
	while (value2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = ft_strdup("0123456789ABCDEF");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	write(fd, result, len);
	free(radix);
	free(result);
	return (len);
}

int			ft_uitoa_base_pf(int fd, uintmax_t value, int base, char x)
{
	int			len;
	uintmax_t	value2;
	char		*radix;
	char		*result;

	len = 1;
	value2 = value;
	while (value2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = (x == 'X') ?
		ft_strdup("0123456789ABCDEF") : ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	write(fd, result, len);
	free(radix);
	free(result);
	return (len);
}
