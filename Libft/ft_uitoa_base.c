/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:57:26 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/18 14:20:37 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa_base(uint32_t n, int base)
{
	int		len;
	int		i;
	char	*str;
	char	*tmp;

	len = 1;
	i = n;
	while (i /= base)
		len++;
	if ((tmp = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	str = ft_strdup("0123456789abcdef");
	tmp[len] = '\0';
	while (len--)
	{
		tmp[len] = str[n % base];
		n /= base;
	}
	len = ft_strlen(tmp);
	free(str);
	return (tmp);
}
