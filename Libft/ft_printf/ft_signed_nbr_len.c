/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_nbr_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:40:31 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/11 14:00:27 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** this returns the number of charectors needed to write the number in full
*/

int		ft_signed_nbr_len(intmax_t value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < -9223372036854775807)
		return (20);
	if (value < 0)
	{
		i++;
		value *= -1;
	}
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

int		ft_unsigned_nbr_len(uintmax_t value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}
