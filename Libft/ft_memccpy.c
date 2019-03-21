/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:29:23 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/22 11:58:12 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	char	*source;
	char	*dest;

	source = (char *)src;
	dest = (char *)dst;
	while (n--)
	{
		*dest = *source;
		dest++;
		if (*source == (char)c)
			return ((void *)dest);
		source++;
	}
	return (NULL);
}
