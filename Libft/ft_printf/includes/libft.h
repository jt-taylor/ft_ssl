/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:51:28 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/16 15:49:09 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define IS_SPAC2(x) (x == '\v' || x == '\n' || x == '\f')
# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || IS_SPACE2(x))
# define FT_ULONG_MAX (((unsigned long)0) - 1)
# define FT_LONG_MAX (FT_ULONG_MAX / 2)
# define FT_LONG_MIN (FT_LONG_MAX + 1)
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
 **	Libc functions ;
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

char			*ft_itoa(int n);
int				ft_atoi(char const *str);
int				ft_tolower(int c);
int				ft_toupper(int c);

char			*ft_strcat(char *s1, char const *s2);
char			*ft_strchr(char const *s1, int c);
char			*ft_strcpy(char *dst, char const *src);
char			*ft_strdup(char const *s);
char			*ft_strncat(char *s1, char const *s2, size_t n);
char			*ft_strncpy(char *dst, char const *src, size_t len);
char			*ft_strnstr(char const *haystack,
								char const *needle, size_t len);
char			*ft_strrchr(char const *s, int c);
char			*ft_strstr(char const *haystack, char const *needle);
int				ft_strcmp(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, char const *src, size_t size);
size_t			ft_strlen(char const *s);
int				ft_strncmp(char const *s1, char const *s2, size_t n);

void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, void const *src, int c, size_t n);
void			*ft_memcpy(void *dst, void const *src, size_t n);
void			*ft_memchr(void const *s, int c, size_t n);
void			*ft_memmove(void *dst, void const *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_memcmp(void const *s1, void const *s2, size_t n);

/*
 ** additional functions ;
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);

void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** bonus functions
*/
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
**	personal functions
*/

char			*ft_strndup(char const *s1, size_t n);
char			*ft_strjoin_free(char const *s1, char const *s2, int nb);
void			ft_putstrarr(char **strarr);
void			ft_str_chr_rplc(char *str, char ch1, char ch2);

#endif
