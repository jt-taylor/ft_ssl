/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 07:49:07 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/31 05:10:05 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ft_ssl_jumptable	*g_ft_ssl_jumptable_array[] =
{
	go_md5,
	go_sha256,
	go_sha224
};

int					search_initial_command(char **argv)
{
	int		i;

	i = 0;
	(ft_strcmp(argv[1], "md5") == 0) ? i = 1 : 0;
	(ft_strcmp(argv[1], "sha256") == 0) ? i = 2 : 0;
	(ft_strcmp(argv[1], "sha224") == 0) ? i = 3 : 0;
	return (i);
}

static void			ft_ssl_parse_from_stdin(t_ssl *t, int confirm_selec,
		char *type)
{
	while (confirm_selec == 0)
	{
		write(1, "ft_ssl> ", 8);
		get_next_line(0, &type);
		if (ft_strcmp(type, "md5") == 0)
			confirm_selec = 1;
		else if (ft_strcmp(type, "sha256") == 0)
			confirm_selec = 2;
		else if (ft_strcmp(type, "sha224") == 0)
			confirm_selec = 3;
		free(type);
	}
	get_all_lines(&type, 0);
	g_ft_ssl_jumptable_array[confirm_selec - 1](type, t);
}

/*
** this one might be what is breaking it
** static void			initialize_struct_options(t_ssl *t, char **argv, int ac)
** {
** 	//ft_printf("here 1\n");
** 	int			n;
**
** 	t->opt_p	= 0;
** 	t->opt_q	= 0;
** 	t->opt_r	= 0;
** 	t->opt_s	= 0;
** 	t->i		= 3;
** 	n			= 1;
** 	while (t->i < ac)
** 	{
** 		if (argv[t->i][n] == '-')
** 			while (argv[t->i][n])
** 			{
** 				(argv[t->i][n] == 'p') ? t->opt_p = 1 : 0;
** 				(argv[t->i][n] == 'q') ? t->opt_q = 1 : 0;
** 				(argv[t->i][n] == 'r') ? t->opt_r = 1 : 0;
** 				if (argv[t->i][n] == 's')
** 				{
** 					t->opt_s++;
** 					t->i++;
** 					break ;
** 				}
** 				n++;
** 			}
** 		else
** 			break ;
** 		n = 0;
** 		t->i++;
** 	}
** 	//
** 	//ft_printf("%d is the value of t_opt_s", t->opt_s);
** 	t->num_files = t->i - ac;
** }
*/

static void			initialize_struct_options(t_ssl *t, char **argv, int ac)
{
	t->i = 2;
	t->opt_p = 0;
	t->opt_q = 0;
	t->opt_r = 0;
	t->opt_s = 0;
	while (t->i < ac)
	{
		if (ft_strcmp(argv[t->i], "-p") == 0)
			t->opt_p = 1;
		else if (ft_strcmp(argv[t->i], "-q") == 0)
			t->opt_q = 1;
		else if (ft_strcmp(argv[t->i], "-r") == 0)
			t->opt_r = 1;
		else if (ft_strcmp(argv[t->i], "-s") == 0)
		{
			t->i++;
			t->opt_s++;
		}
		else
			break ;
		t->i++;
	}
	t->num_files = t->i - ac;
}

static void			ft_ssl_distribute_hash(t_ssl *t, char **argv, int ac,
		int index)
{
	initialize_struct_options(t, argv, ac);
	if (t->opt_p || (!t->num_files && !t->opt_s))
	{
		get_all_lines(&t->input_stream, 0);
		if (t->opt_p)
			ft_putstr(t->input_stream);
		g_ft_ssl_jumptable_array[index - 1](t->input_stream, t);
		ft_putchar('\n');
		free(t->input_stream);
	}
	t->file_counter = 2;
	while (t->file_counter < ac)
		if (ft_ssl_s_flag_hash(t, argv, ac) == -1)
			break ;
	while (t->file_counter < ac)
		ft_ssl_handle_files_hash(t, argv);
}

int					main(int ac, char **argv)
{
	t_ssl		t;

	if (ac == 1)
	{
		ft_ssl_parse_from_stdin(&t, 0, NULL);
		return (0);
	}
	else if ((search_initial_command(argv) > 0)
			&& (search_initial_command(argv) <= 3))
		ft_ssl_distribute_hash(&t, argv, ac, search_initial_command(argv));
	else
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard \
commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher \
commands:\n", argv[1]);
	return (0);
}
