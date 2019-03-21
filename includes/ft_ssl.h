/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 07:49:39 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/20 23:13:02 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Things to do -------------------------------------------------------------->
*/

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct	s_ssl
{
	int			opt_p;
	int			opt_q;
	int			opt_r;
	int			opt_s;

	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;

	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;

	uint32_t	f;
	uint32_t	g;
	uint32_t	*tmp;
	uint32_t	tmp1;

	int			i;
	int			num_files;
	int			new_len;
	int			offset;
	char		*msg;

	int			fd;
	char		*input_stream;
	int			file_counter;
}				t_ssl;

/*
** main.c
*/
int				search_initial_command(char **argv);

/*
** misc_functions
*/
char						*ft_ssl_add0(char *str);
void						*ft_bzero_return(void *s, size_t n);
uint32_t					ft_ssl_reverse_uint32(uint32_t n);

/*
** go_fun.c
*/
void						go_md5(char *std, t_ssl *t);

/*
** ft_ssl_handle_string_flag.c
*/
int			ft_ssl_s_flag_hash(t_ssl *t, char **argv, int ac);

/*
** ft_ssl_md5.c
*/
int							md5(unsigned char *msg, size_t len, t_ssl *t);

/*
** ft_handle_files_hash.c
*/


void						ft_ssl_handle_files_hash(t_ssl *t, char **argv);


/*
** function pointers
*/
typedef void				ft_ssl_jumptable(char *, t_ssl *);
//extern ft_ssl_jumptable		ft_ssl_jumptable_array[];

// the array size value needs to be updated for each new function added;
extern ft_ssl_jumptable *ft_ssl_jumptable_array[1];
/*
**extern ft_ssl_jumptable *ft_ssl_jumptable_array[] =
**{
**	go_md5
**};
*/

#endif