# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 23:03:06 by abeh              #+#    #+#              #
#    Updated: 2024/05/30 23:03:06 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c \
		ft_print_percent.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_nbr.c \
		ft_print_unsigned.c \
		ft_print_hex.c

OBJS = $(SRCS:.c=.o)

LIBFT = ../libft.a
LIBFT_DIR = ../libft

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@echo "\n ft_printf Cleaned!\n"
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean
	make $(NAME)