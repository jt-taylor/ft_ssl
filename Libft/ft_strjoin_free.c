/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:43:28 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/29 19:14:24 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int nb)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		if (nb == 1 || nb == 3)
			free((char *)s1);
		if (nb == 2 || nb == 3)
			free((char *)s2);
	}
	return (result);
}
