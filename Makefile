# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 03:03:04 by jtaylor           #+#    #+#              #
#    Updated: 2019/03/31 03:15:52 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC = main.c \
	  misc_functions.c \
	  go_func.c \
	  ft_ssl_sha256.c \
	  ft_ssl_md5.c \
	  ft_ssl_handle_string_flag.c \
	  ft_handle_hash_input_files.c

#OBJ = $(SRC:.c=.o)

GCCFLAGS = -Wall -Wextra -Werror

#%.o: %.c
#	gcc $(GCCFLAGS) -c $< $@ -I ./includes

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	make -C ./Libft
	gcc $(GCCFLAGS) $(SRC) -I ./includes ./Libft/libft.a \
		./Libft/ft_printf/libftprintf.a -o $(NAME)

clean:
	make clean -C ./Libft

fclean:
	rm -f $(NAME)
	make fclean -C ./Libft

re: fclean all
