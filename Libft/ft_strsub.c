/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 12:09:34 by jtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 10:47:30 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sptr;
	int		index;

	if (!s)
		return (NULL);
	if (!(sptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	while (len - index)
	{
		sptr[index] = s[start + index];
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}
