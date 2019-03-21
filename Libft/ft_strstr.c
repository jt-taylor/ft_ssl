/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:12:24 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 10:09:12 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *needle)
{
	unsigned i;

	if (!*needle)
		return ((char *)str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] == needle[i])
		{
			if (!needle[i + 1])
				return ((char *)str);
			++i;
		}
		++str;
	}
	return (NULL);
}
