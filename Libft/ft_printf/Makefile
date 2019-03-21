# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 11:33:14 by jtaylor           #+#    #+#              #
#    Updated: 2019/02/11 22:33:47 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FT_PRINTF_SRC = ft_printf.c \
				ft_printf_char.c ft_printf_decimal.c \
				ft_printf_decimal_padding.c ft_printf_hexadecimal.c \
				ft_printf_itoa_base.c ft_printf_octal.c \
				ft_printf_parse_modifiers.c ft_printf_parsing.c \
				ft_printf_percent.c ft_printf_pointer.c ft_printf_string.c \
				ft_printf_unsigned_decimal.c ft_signed_nbr_len.c \
				ft_print_binary.c ft_printf_float.c ft_itoa.c \
				ft_printf_ftoa_converter.c

LIBFT_PATH = ./
LIBFT_SRC_PATH = ft_atoi.c \
				 ft_isdigit.c \
				 ft_memalloc.c \
				 ft_bzero.c \
				 ft_strchr.c \
				 ft_strdup.c \
				 ft_strlen.c \
				 ft_strnew.c \
				 ft_strlen.c \
				 ft_strcat.c

OBJ += $(FT_PRINTF_SRC:.c=.o)
OBJ += $(addprefix $(LIBFT_PATH),$(LIBFT_SRC_PATH:.c=.o))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ar -s $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I ./includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
