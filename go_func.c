/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:45:06 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/31 05:05:38 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			go_md5(char *std, t_ssl *t)
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

static void		print_sha_256_cont(t_ssl *t)
{
	char	*tmp;

	tmp = ft_uitoa_base(t->h3, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h4, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h5, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h6, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h7, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void			go_sha256(char *std, t_ssl *t)
{
	char	*tmp;

	if (sha256(std, ft_strlen(std), t) == -1)
		return ;
	tmp = ft_uitoa_base(t->h0, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h1, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h2, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	print_sha_256_cont(t);
}

static void		print_sha224(t_ssl *t)
{
	char	*tmp;

	tmp = ft_uitoa_base(t->h3, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h4, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h5, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h6, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void			go_sha224(char *std, t_ssl *t)
{
	char	*tmp;

	if (sha224(std, ft_strlen(std), t) == -1)
		return ;
	tmp = ft_uitoa_base(t->h0, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h1, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = ft_uitoa_base(t->h2, 16);
	ft_ssl_add0(tmp);
	ft_putstr(tmp);
	free(tmp);
	print_sha224(t);
}
