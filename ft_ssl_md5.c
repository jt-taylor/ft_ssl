/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:37:11 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/21 07:37:02 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** g_s == shift amount , name is short for norm --------------------------------
** g_c == the constant values precomputed (is based on sin() fnuctions ---------
*/

static const uint32_t	g_s[] = {7, 12, 17, 22, 7, 12, 17, 22, 7,
	12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16,
	23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15,
	21, 6, 10, 15, 21, 6, 10, 15, 21};

static const uint32_t	g_c[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static uint32_t			left_rotate(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

static void				md5_func(t_ssl *t, int i)
{
	if (i < 16)
	{
		t->f = (t->b & t->c) | ((~t->b) & t->d);
		t->g = i;
	}
	else if (i < 32)
	{
		t->f = (t->d & t->b) | ((~t->d) & t->c);
		t->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		t->f = t->b ^ t->c ^ t->d;
		t->g = (3 * i + 5) % 16;
	}
	else if (i < 64)
	{
		t->f = t->c ^ (t->b | (~t->d));
		t->g = (7 * i) % 16;
	}
	t->tmp1 = t->d;
	t->d = t->c;
	t->c = t->b;
	t->b = t->b + left_rotate((t->a + t->f + g_c[i] + t->tmp[t->g]), g_s[i]);
	t->a = t->tmp1;
}

static int				preprosses(unsigned char *msg, size_t len, t_ssl *t)
{
	t->h0 = 0x67452301;
	t->h1 = 0xefcdab89;
	t->h2 = 0x98badcfe;
	t->h3 = 0x10325476;
	t->new_len = len + 1;
	while (t->new_len % 64 != 56)
		t->new_len++;
	if (!(t->msg = malloc(t->new_len + 64)))
		return (-1);
	t->msg = ft_bzero_return(t->msg, t->new_len + 64);
	ft_strcpy((char *)t->msg, (const char *)msg);
	*(uint32_t *)(t->msg + len) = 0x80;
	*(uint32_t *)(t->msg + t->new_len) = (uint32_t)(8 * len);
	t->offset = 0;
	return (0);
}

int						md5(unsigned char *msg, size_t len, t_ssl *t)
{
	int		i;

	if (preprosses(msg, len, t) == -1)
		return (-1);
	while (t->offset < t->new_len)
	{
		t->tmp = (uint32_t *)(t->msg + t->offset);
		t->a = t->h0;
		t->b = t->h1;
		t->c = t->h2;
		t->d = t->h3;
		i = -1;
		while (++i < 64)
			md5_func(t, i);
		t->h0 += t->a;
		t->h1 += t->b;
		t->h2 += t->c;
		t->h3 += t->d;
		t->offset += 64;
	}
	free(t->msg);
	return (0);
}
