/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hash_input_files.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:33:38 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/20 16:40:15 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int					no_such_file(t_ssl *t, char **argv)
{
	int	i;

	i = search_initial_command(argv);
	if ((t->fd = open(argv[t->file_counter], O_RDWR)) < 0)
	{
		(i = 1) ? ft_putstr("ft_ssl: md5: ") : 0;
		ft_printf("%s: Invalid file or dir (?)\n", argv[t->file_counter]);
		t->file_counter++;
		return (-1);
	}
	return (0);
}

void						ft_ssl_handle_files_hash_no_rotate(t_ssl *t,
		char **argv)
{
	int	i;

	i = search_initial_command(argv);
	if (!t->opt_q)
{
		(i = 1) ? ft_putstr("MD5 (") : 0;
		ft_printf("%s) = ", argv[t->file_counter]);
	}
	ft_ssl_jumptable_array[i - 1](t->input_stream, t);
	ft_putchar('\n');
}

void						ft_ssl_handle_files_hash_rotate(t_ssl *t,
		char **argv)
{
	int i;

	i = search_initial_command(argv);
	ft_ssl_jumptable_array[i - 1](t->input_stream, t);
	if (!t->opt_q)
		ft_printf(" %s\n", argv[t->file_counter]);
	else
		ft_putchar('\n');
}

void						ft_ssl_handle_files_hash(t_ssl *t, char **argv)
{
	if (no_such_file(t, argv) == -1)
		return ;
	get_all_lines(&t->input_stream, t->fd);
	if (!t->opt_r)
		ft_ssl_handle_files_hash_no_rotate(t, argv);
	else
		ft_ssl_handle_files_hash_rotate(t, argv);
	free(t->input_stream);
	close(t->fd);
	t->file_counter++;
}
