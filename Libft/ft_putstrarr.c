/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:23:49 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/14 12:25:18 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **strarr)
{
	size_t	i;

	if (strarr)
	{
		i = 0;
		while (strarr[i] != NULL)
		{
			ft_putstr(strarr[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
