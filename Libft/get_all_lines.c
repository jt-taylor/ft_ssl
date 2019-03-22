/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:36:46 by jtaylor           #+#    #+#             */
/*   Updated: 2019/03/21 07:34:27 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** add this to the header and the makefile
*/
#include "libft.h"

void		get_all_lines(char **line, int fd)
{
	char		add_char[2];
	char		*tmp;
	char		*str;
	int			i;

	i = 1;
	add_char[1] = 0;
	str = ft_strdup("");
	while (i > 0)
	{
		i = read(fd, add_char, 1);
		if (i == 0)
			break ;
		tmp = str;
		str = ft_strjoin(str, add_char);
		free(tmp);
	}
	line[0] = str;
}
