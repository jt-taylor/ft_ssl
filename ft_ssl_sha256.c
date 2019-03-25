/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 07:00:04 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/25 02:47:24 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** somewhere in here something is wrong don't i just love debugging
** also delete me if this get fixed or it will look really awkward in the 
** correction
*/
/*
** the array of constants ------------------------------------------------------
*/
static const uint32_t		g_const_array[] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

/*
** the rotate function
*/
static uint32_t				rightrotate(uint32_t x, uint32_t n)
{
	return ((((unsigned int)x >> n )) | (x << (32 - n)));
}

/*
** set up the buffers ----------------------------------------------------------
*/
static int					preprosses_sha256(char *init, size_t len, t_ssl *t)
{
	int		i;

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
	if (!(t->tmp = malloc(16 * t->offset * 4)))
		return (-1);
	ft_bzero(t->tmp, 16 * t->offset * 4);
	ft_memcpy((char *)t->tmp, init, ft_strlen(init));
	((char *)t->tmp)[ft_strlen(init)] = 0x80;
	i = 0;
	while (i < (t->offset *  16) - 1)
	{
		t->tmp[i] = ft_ssl_reverse_uint32(t->tmp[i]);
		i++;
	}
	t->tmp[((t->offset * 512 - 64) / 32) + 1] = t->new_len;
	return (0);
}

/*
** set up the a -> h word values
*/
static void		schedule_array(t_ssl *t, int i)
{
	int	j;

	t->tmp_sha = malloc(512);
	ft_bzero(t->tmp_sha, 512);
	ft_memcpy(t->tmp_sha, &t->tmp[i * 16], 512);
	j = 16;
	while (j < 16)
	{
		t->tmp_sha4 = rightrotate(t->tmp_sha[j - 15], 7) ^
			rightrotate(t->tmp_sha[j - 15], 18) ^ (t->tmp_sha[j - 15] >> 3);
		t->tmp_sha0 = rightrotate(t->tmp_sha[j - 2], 17) ^
			rightrotate(t->tmp_sha[j - 2], 19) ^ (t->tmp_sha[j - 2] >> 10);
		t->tmp_sha[j] = t->tmp_sha[j - 16] + t->tmp_sha4 + t->tmp_sha[j - 7] +
			t->tmp_sha0;
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

/*
** the algorithim that does all of the bitshifting
*/
static void		sha_256_alg(t_ssl *t, int j)
{
	t->tmp_sha0 = rightrotate(t->e, 6) ^ rightrotate(t->e, 11) ^
		rightrotate(t->e, 25);
	t->tmp_sha2 = (t->e & t->f) ^ ((~t->e) & (t->g));
	t->tmp_sha3 = t->h + t->tmp_sha0 + t->tmp_sha2 + g_const_array[j] + t->tmp_sha[j];
	t->tmp_sha4 = rightrotate(t->a, 2) ^ rightrotate(t->a, 13) ^ rightrotate
		(t->a, 22);
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

/*
** thhe main function for sha256
*/
int								sha256(char *init, size_t len, t_ssl *t)
{
	int		i;
	int		j;

	preprosses_sha256(init, len, t);
	i = 0;
	while (i < t->offset)
	{
		schedule_array(t, i);
		j = -1;
		while (++j < 64)
			sha_256_alg(t, j);
		t->h0 += t->a;
		t->h1 += t->b;
		t->h2 += t->c;
		t->h3 += t->d;
		t->h4 += t->e;
		t->h5 += t->f;
		t->h6 += t->g;
		t->h7 += t->h;
		free(t->tmp_sha);
		i++;
	}
	free(t->tmp);
	return (0);
}
