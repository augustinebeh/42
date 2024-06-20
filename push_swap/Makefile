# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 06:45:50 by abeh              #+#    #+#              #
#    Updated: 2024/06/19 16:57:11 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_A = libft.a
LIBFT = libft/

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

RM = rm -rf

$(NAME):	$(OBJS) $(LIBFT_A)
				@gcc $(OBJS) $(LIBFT_A) -o $@ \
	-I includes -I $(LIBFT)/includes

do_libft:
				@cd $(LIBFT) && $(MAKE) libft.a

all:			do_libft $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all
