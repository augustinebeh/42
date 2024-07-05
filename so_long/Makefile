# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 04:52:58 by abeh              #+#    #+#              #
#    Updated: 2024/07/05 16:55:58 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c

OBJS = ${SRCS:.c=.o}

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "so_long is ready to use!"

clean:
	@{RM} ${OBJS} ${OBJSB}
	@echo "so_long's object files are deleted!"

fclean: clean
	@${RM} ${NAME}
	@echo "${NAME} is deleted!"

re: fclean all

.PHONY: all clean fclean re
