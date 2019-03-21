/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:54:57 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 14:43:34 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(char const *str)
{
	int		negative;
	int		value;

	negative = 0;
	value = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		value = (value * 10) + (*str - 48) % 10;
		str++;
	}
	if (negative)
		return (value > 2147483647 ? -2147483647 : (int)-value);
	else
		return (value > 2147483647 ? 2147483647 : (int)value);
}
