# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 06:45:50 by abeh              #+#    #+#              #
#    Updated: 2024/07/02 10:13:37 by abeh             ###   ########.fr        #
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

RM = rm -rf

all:	 ${NAME}

${NAME}: 	${OBJS}


${CHECK}: ${CHECK_OBJS}
	@ar rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@
clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${OBJS} ${NAME}

re: fclean all

.PHONY: all clean fclean re
