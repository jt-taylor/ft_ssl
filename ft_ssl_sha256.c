/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 07:00:04 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/27 22:21:27 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** I have no idea how but sometimes on specific strings it losses athe first
** char of data ???
*/

const uint32_t g_k2[] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa,
	0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138,
	0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624,
	0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f,
	0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

int			sha256_prepross(char *init_mg, size_t len, t_ssl *t)
{
	int i;

	t->h0 = 0x6a09e667;
	t->h1 = 0xbb67ae85;
	t->h2 = 0x3c6ef372;
	t->h3 = 0xa54ff53a;
	t->h4 = 0x510e527f;
	t->h5 = 0x9b05688c;
	t->h6 = 0x1f83d9ab;
	t->h7 = 0x5be0cd19;
	t->new_len = len * 8;
	t->offset = 1 + ((t->new_len + 16 + 64) / 512);
	if (!(t->tmp_sha_ptr = malloc(16 * t->offset * 4)))
		return (-1);
	ft_bzero(t->tmp_sha_ptr, 16 * t->offset * 4);
	ft_memcpy((char *)t->tmp_sha_ptr, init_mg, ft_strlen(init_mg));
	((char*)t->tmp_sha_ptr)[ft_strlen(init_mg)] = 0x80;
	i = 0;
	while (i < (t->offset * 16) - 1)
	{
		t->tmp_sha_ptr[i] = ft_ssl_reverse_uint32(t->tmp_sha_ptr[i]);
		i++;
	}
	t->tmp_sha_ptr[((t->offset * 512 - 64) / 32) + 1] = t->new_len;
	return (0);
}

void		schedule_array(t_ssl *t, int i)
{
	int j;

	t->tmp = malloc(512);
	ft_bzero(t->tmp, 512);
	ft_memcpy(t->tmp, &t->tmp_sha_ptr[i * 16], 16 * 32);
	j = 16;
	while (j < 64)
	{
		t->tmp_sha4 = rigthrotat(t->tmp[j - 15], 7) ^
		rigthrotat(t->tmp[j - 15], 18) ^ (t->tmp[j - 15] >> 3);
		t->tmp_sha1 = rigthrotat(t->tmp[j - 2], 17) ^
		rigthrotat(t->tmp[j - 2], 19) ^ (t->tmp[j - 2] >> 10);
		t->tmp[j] = t->tmp[j - 16] + t->tmp_sha4 + t->tmp[j - 7] + t->tmp_sha1;
		j++;
	}
	t->a = t->h0;
	t->b = t->h1;
	t->c = t->h2;
	t->d = t->h3;
	t->e = t->h4;
	t->f = t->h5;
	t->g = t->h6;
	t->h = t->h7;
}

void		sha256_algo(t_ssl *t, int j)
{
	t->tmp_sha1 = rigthrotat(t->e, 6) ^ rigthrotat(t->e, 11) ^ rigthrotat(t->e, 25);
	t->tmp_sha2 = (t->e & t->f) ^ ((~t->e) & t->g);
	t->tmp_sha3 = t->h + t->tmp_sha1 + t->tmp_sha2 + g_k2[j] + t->tmp[j];
	t->tmp_sha4 = rigthrotat(t->a, 2) ^ rigthrotat(t->a, 13) ^ rigthrotat(t->a, 22);
	t->tmp_sha5 = (t->a & t->b) ^ (t->a & t->c) ^ (t->b & t->c);
	t->tmp_sha6 = t->tmp_sha4 + t->tmp_sha5;
	t->h = t->g;
	t->g = t->f;
	t->f = t->e;
	t->e = t->d + t->tmp_sha3;
	t->d = t->c;
	t->c = t->b;
	t->b = t->a;
	t->a = t->tmp_sha3 + t->tmp_sha6;
}

int			sha256(char *init_mg, size_t len, t_ssl *t)
{
	int i;
	int j;

	sha256_prepross(init_mg, len, t);
	i = 0;
	while (i < t->offset)
	{
		schedule_array(t, i);
		j = -1;
		while (++j < 64)
			sha256_algo(t, j);
		t->h0 += t->a;
		t->h1 += t->b;
		t->h2 += t->c;
		t->h3 += t->d;
		t->h4 += t->e;
		t->h5 += t->f;
		t->h6 += t->g;
		t->h7 += t->h;
		free(t->tmp);
		i++;
	}
	free(t->tmp_sha_ptr);
	return (0);
}
