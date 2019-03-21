/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:47:03 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/19 18:57:45 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char				*ft_ssl_add0(char *str)
{
	int		i;

	 i = ft_strlen(str);
	 while (i < 8)
	 {
		 ft_putchar('0');
		 i++;
	 }
	 return (str);
}

void			*ft_bzero_return(void *s, size_t n)
{
	unsigned char	*i;
	size_t			b;

	b = 0;
	i = (unsigned char *)s;
	while (b < n)
	{
		i[b] = '\0';
		b++;
	}
	return (s);
}

uint32_t			ft_ssl_reverse_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
		((n & 0xff00) << 8) | (n << 24));
}
