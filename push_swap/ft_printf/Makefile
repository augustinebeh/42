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

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c 			\
		ft_print_percent.c 		\
		ft_print_char.c			\
		ft_print_str.c 			\
		ft_print_nbr.c 			\
		ft_print_pointer.c 		\
		ft_print_unsigned.c 		\
		ft_print_hex.c

OBJS = $(SRCS:.c=.o)

RM	= rm -f


all: 		$(NAME)

$(NAME): 	$(OBJS)
			@ar rcs $(NAME) $(OBJS)


.c.o:
			$(CC) $(CFLAGS) -c $< -o $@


clean:
			@$(RM) $(OBJS)
			@echo "\n	all .o files  removed!\n"

fclean:
			@$(RM) $(OBJS) $(NAME)
			@echo "\nall .o files  removed!"
			@echo "libftprintf.a removed!\n"

re: 		fclean all

