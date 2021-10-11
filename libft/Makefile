# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ksmorozo <ksmorozo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/10 19:37:56 by ksmorozo      #+#    #+#                  #
#    Updated: 2021/10/11 16:57:21 by ksmorozo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_itoa_base.c \
ft_putchar_fd.c ft_strdup.c \
ft_strjoin.c ft_strlen.c \
ft_strlcpy.c ft_memcpy.c \
ft_putnbr_fd.c \
ft_bzero.c

HEADER_FILES = libft.h
CFLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

%.o: %.c $(HEADER)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
