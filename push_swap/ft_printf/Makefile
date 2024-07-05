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

SUBDIR = libft
LIBNAME = libft.a

RM	= rm -rf

all: 		${LIBNAME} ${NAME}

${LIBNAME} :
	${MAKE} bonus -C ${SUBDIR}
	cp ${SUBDIR}/${LIBNAME} .
	${RM} ${SUBDIR}/*.o

${NAME}: ${OBJS} ${LIBNAME}
	ar rcs ${NAME} ${OBJS} ${LIBNAME}
	@echo "ar rcs ${NAME} ${LIBNAME} *.o"

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}
	@$(MAKE) -C ${SUBDIR} clean
	@echo "clean ${NAME}"

fclean:
	@${RM} ${OBJS} ${NAME} ${LIBNAME}
	@$(MAKE) -C ${SUBDIR} fclean
	@echo "fclean ${NAME}"

re: 		fclean all

.PHONY: clean fclean re all
