# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 04:52:58 by abeh              #+#    #+#              #
#    Updated: 2024/07/06 04:38:23 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c

OBJS = ${SRCS:.c=.o}

LIBFTPRINTF = ft_printf/libftprintf.a
LIBFT = ft_printf/libft.a

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFTPRINTF} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFTPRINTF} ${LIBFT} -o ${NAME}

${LIBFTPRINTF}:
	make -C ft_printf

${LIBFT}:
	make -C ft_printf/libft

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}
	@$(MAKE) -C ft_printf clean
	@echo "clean ${NAME}"

fclean:
	@${RM} ${OBJS} ${NAME} ${LIBFTPRINTF} ${LIBFT}
	@$(MAKE) -C ft_printf fclean
	@echo "fclean ${NAME}"

re: fclean all

.PHONY: clean fclean re all
