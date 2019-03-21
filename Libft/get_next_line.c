/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:48:12 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/05 11:29:23 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

/*
**	input	:	char *str, char **max ;
**
**	action	:	set *max = strdup(str) via char *tmp
**					free tmp;
**
** 	return	:	function type void
*/

static void		store_max(char *str, char **max)
{
	char	*tmp;

	if (*str)
	{
		tmp = *max;
		*max = ft_strdup(str);
		free(tmp);
	}
}

/*
**	input	:	char **line, char **max, char **end_line ;
**
** 	action	:
**
** 	return	:	1 ,for end of line , or 0;
*/

static int		use_max(char **line, char **max, char **end_line)
{
	if (*max && **max)
	{
		if ((*end_line = ft_strchr(*max, '\n')))
		{
			**end_line = '\0';
			*line = ft_strjoin_free(*line, *max, 1);
			store_max(++(*end_line), max);
			if (ft_strequ(*max, *line))
				ft_strclr(*max);
			return (1);
		}
		else
			*line = ft_strjoin_free(*line, *max, 1);
		if (!ft_strchr(*max, '\n'))
			ft_strclr(*max);
	}
	return (0);
}

/*
** input 	:	int fd, char **line ;
**
** action	: reads and displays lines from a file to a given file descriptor
**
** return	: int for error checking;
*/

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		*end_line;
	char		buf[BUFF_SIZE + 1];
	static char	*max[OPEN_MAX];

	if (fd < 0 || !line || (fd > OPEN_MAX))
		return (-1);
	*line = ft_strnew(0);
	if (use_max(line, &max[fd], &end_line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((end_line = ft_strchr(buf, '\n')))
		{
			*end_line = '\0';
			store_max(++end_line, &max[fd]);
			*line = ft_strjoin_free(*line, buf, 1);
			return (1);
		}
		*line = ft_strjoin_free(*line, buf, 1);
	}
	if (**line && ret == 0)
		return (1);
	return (ret);
}
