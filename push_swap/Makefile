# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 06:45:50 by abeh              #+#    #+#              #
#    Updated: 2024/07/04 07:19:36 by abeh             ###   ########.fr        #
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

SUBDIR = ft_printf
LIBNAME = libftprintf.a

RM = rm -rf

all:	 ${NAME}

${LIBNAME} :
	${MAKE} -C ${SUBDIR}
	cp ${SUBDIR}/${LIBNAME} .

${NAME}: ${OBJS} ${LIBNAME}
	${CC} ${CFLAGS} ${OBJS} -L. -lftprintf -o ${NAME}


${CHECK}: ${CHECK_OBJS}
	@ar rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@
clean:
	@${RM} ${OBJS}
	$(MAKE) -C ft_printf clean

fclean: clean
	@${RM} ${OBJS} ${NAME}
	@${RM} ${LIBNAME}
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
