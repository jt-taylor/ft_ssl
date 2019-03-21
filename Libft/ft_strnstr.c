/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:57:41 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 10:19:19 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *needle, size_t len)
{
	unsigned i;
	unsigned k;

	if (!*needle)
		return ((char *)str);
	k = 0;
	while (str[k] && k < len)
	{
		i = 0;
		while (str[k + i] && str[k + i] == needle[i] && k + i < len)
		{
			if (!needle[i + 1])
				return ((char *)str + k);
			++i;
		}
		++k;
	}
	return (NULL);
}
