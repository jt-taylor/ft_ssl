/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:45:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/19 19:27:08 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		go_md5(char *std, t_ssl *t)
{
	char *tmp;

	if (md5((uint8_t *)std, ft_strlen(std), t) == -1)
		return ;
	tmp = ft_uitoa_base(ft_ssl_reverse_uint32(t->h0), 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(ft_ssl_reverse_uint32(t->h1), 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(ft_ssl_reverse_uint32(t->h2), 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(ft_ssl_reverse_uint32(t->h3), 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}
