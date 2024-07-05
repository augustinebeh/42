# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 04:52:58 by abeh              #+#    #+#              #
#    Updated: 2024/07/05 16:36:42 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c

OBJS = ${SRCS:.c=.o}

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "Pipex is ready to use!"

clean:
	@{RM} ${OBJS} ${OBJSB}
	@echo "Pipex's object files are deleted!"

fclean: clean
	@${RM} ${NAME}
	@echo "${NAME} is deleted!"

re: fclean all

.PHONY: all clean fclean re
