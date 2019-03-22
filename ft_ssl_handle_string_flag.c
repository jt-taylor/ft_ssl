/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_handle_string_flag.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:53:28 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/21 08:29:18 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void					ft_ssl_no_rotate_string(t_ssl *t, char **argv)
{
	int		i;

	i = search_initial_command(argv);
	if (!t->opt_q)
	{
		(i = 1) ? ft_putstr("MD5 (\"") : 0;
		ft_printf("%s\") = ", argv[t->file_counter]);
	}
	g_ft_ssl_jumptable_array[i - 1](argv[t->file_counter], t);
	ft_putchar('\n');
}

/*
static void					ft_ssl_rotate_string(t_ssl *t, char **argv)
**	{
**		int	i;
**
**		i = search_initial_command(argv);
**		if (i == 1)
**			ft_printf("MD5 (\"%s\") = ", argv[t->file_counter]);
**		g_ft_ssl_jumptable_array[i - 1](argv[t->file_counter], t);
**		if (!t->opt_q)
**			ft_printf(" \"%s\"\n", argv[t->file_counter]);
**		else
**			ft_putchar('\n');
**	}
*/

static void					ft_ssl_rotate_string(t_ssl *t, char **argv)
{
	int	i;

	i = search_initial_command(argv);
	g_ft_ssl_jumptable_array[i - 1](argv[t->file_counter], t);
	if (!t->opt_q)
		ft_printf(" \"%s\"\n", argv[t->file_counter]);
	else
		ft_putchar('\n');
}

int							ft_ssl_s_flag_hash(t_ssl *t, char **argv, int ac)
{
	if (ft_strcmp("-p", argv[t->file_counter]) == 0)
		t->opt_p = 1;
	else if (ft_strcmp("-q", argv[t->file_counter]) == 0)
		t->opt_q = 1;
	else if (ft_strcmp("-r", argv[t->file_counter]) == 0)
		t->opt_r = 1;
	else if (ft_strcmp("-s", argv[t->file_counter]) == 0)
	{
		t->file_counter++;
		if (t->file_counter < ac)
		{
			if (!t->opt_r)
				ft_ssl_no_rotate_string(t, argv);
			else
				ft_ssl_rotate_string(t, argv);
		}
	}
	else
		return (-1);
	t->file_counter++;
	return (0);
}
