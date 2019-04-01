/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 07:49:39 by jtaylor           #+#    #+#             */
/*   Updated: 2019/04/01 16:56:25 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Things to do -------------------------------------------------------------->
** when using the -r and the -s flags together the md5 prefix is still added-->
*/

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct				s_ssl
{
	int			opt_p;
	int			opt_q;
	int			opt_r;
	int			opt_s;

	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	h4;
	uint32_t	h5;
	uint32_t	h6;
	uint32_t	h7;

	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;

	uint32_t	*tmp;
	uint32_t	*tmp_sha_ptr;
	uint32_t	tmp_sha0;
	uint32_t	tmp_sha1;
	uint32_t	tmp_sha2;
	uint32_t	tmp_sha3;
	uint32_t	tmp_sha4;
	uint32_t	tmp_sha5;
	uint32_t	tmp_sha6;

	uint32_t	tmp1;

	int			i;
	int			num_files;
	int			new_len;
	int			offset;
	char		*msg;

	int			fd;
	char		*input_stream;
	int			file_counter;
}							t_ssl;

/*
** main.c
*/
int							search_initial_command(char **argv);

/*
** misc_functions
*/
char						*ft_ssl_add0(char *str);
void						*ft_bzero_return(void *s, size_t n);
uint32_t					ft_ssl_reverse_uint32(uint32_t n);
uint32_t					rigthrotat(uint32_t x, uint32_t n);

/*
** go_fun.c
*/
void						go_md5(char *std, t_ssl *t);
void						go_sha256(char *std, t_ssl *t);
void						go_sha224(char *std, t_ssl *t);

/*
** ft_ssl_handle_string_flag.c
*/
int							ft_ssl_s_flag_hash(t_ssl *t, char **argv, int ac);

/*
** ft_ssl_md5.c
*/
int							md5(unsigned char *msg, size_t len, t_ssl *t);

/*
** ft_handle_files_hash.c
*/

void						ft_ssl_handle_files_hash(t_ssl *t, char **argv);

/*
** ft_ssl_sha256
*/

int							sha256(char *init, size_t len, t_ssl *t);

/*
** I wanted to do whirlpool but i gotta get something graded soon
** so sha224 it is i guess
** ft_ssl_sha224.c
*/

int							sha224(char *init_mg, size_t len, t_ssl *g);

/*
** function pointers
** //extern ft_ssl_jumptable		ft_ssl_jumptable_array[];
** // the array size value needs to be updated for each new function added;
*/
typedef void				t_ft_ssl_jumptable(char *str, t_ssl *t);
extern t_ft_ssl_jumptable	*g_ft_ssl_jumptable_array[];
/*
**extern ft_ssl_jumptable *ft_ssl_jumptable_array[] =
**{
**	go_md5
**};
*/

/*
** testing
*/
char						*ft_unsigned_itoa_base(uint32_t n, int base);

#endif
