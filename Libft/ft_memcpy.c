/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:58:47 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/21 12:50:46 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t len)
{
	size_t	i;
	char	*ptr;
	char	*ptr2;

	ptr = dst;
	ptr2 = (char *)src;
	i = -1;
	while (++i < len)
		*(ptr + i) = *(ptr2 + i);
	return (dst);
}
