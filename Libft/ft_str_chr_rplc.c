/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr_rplc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:45:18 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/16 15:48:37 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_chr_rplc(char *str, char ch1, char ch2)
{
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	while (*ptr)
	{
		if (*ptr == ch1)
			*ptr = ch2;
		ptr++;
	}
	if (*ptr == ch1)
		*ptr = ch2;
}
