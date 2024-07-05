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

OBJS = ${SRCS:.c=.o}

RM	= rm -rf

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: 	${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "ar rcs ${NAME} *.o"
	@echo "${NAME} is ready to use!"

all: 		${NAME}

clean:
	@rm -rf ${OBJS}
	@echo "Libftprintf's object files are deleted!"

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} is deleted!"

re: 		fclean all

.PHONY: clean fclean re all
