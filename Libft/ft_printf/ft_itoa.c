/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:24:51 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/22 20:20:55 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digits(int nbr)
{
	int	count;

	count = nbr < 0 ? 2 : 1;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		++count;
	}
	return (count);
}

static void		int_to_str(int nbr, char *str, int *count)
{
	if (nbr >= 10 || nbr <= -10)
	{
		int_to_str(nbr / 10, str, count);
		int_to_str(nbr % 10, str, count);
	}
	else
	{
		str[*count] = nbr < 0 ? (nbr * -1) + 48 : nbr + 48;
		*count += 1;
	}
}

char			*ft_itoa(int nbr)
{
	char	*out;
	int		size;
	int		count;

	size = digits(nbr) + 1;
	out = (char *)malloc(sizeof(char) * size);
	if (!out)
		return (NULL);
	count = 0;
	if (nbr < 0)
	{
		out[0] = '-';
		++count;
	}
	int_to_str(nbr, out, &count);
	out[size - 1] = '\0';
	return (out);
}
