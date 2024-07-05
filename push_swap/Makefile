# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 06:45:50 by abeh              #+#    #+#              #
#    Updated: 2024/07/06 04:42:20 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =  	instructions_pa_pb.c \
			instructions_ra_rb_rr.c \
			instructions_rra_rrb_rrr.c \
			instructions_sa_sb_ss.c \
			index_elements.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			push_swap.c \
			mini_algo.c \
			major_algo.c


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
