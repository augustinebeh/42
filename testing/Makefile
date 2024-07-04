# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 18:01:09 by abeh              #+#    #+#              #
#    Updated: 2024/07/04 06:23:13 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = program

cc = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror

srcs = 	hello.c \
			world.c \
			main.c

objs = $(srcs:.c=.o)

SUBDIR = libft
LIBNAME = libft.a

all: $(name)

$(LIBNAME):
	$(MAKE) -C $(SUBDIR)
	cp $(SUBDIR)/$(LIBNAME) .

$(name): $(objs) $(LIBNAME)
	$(cc) $(CFLAGS) $(objs) -L. -lft -o $(name)
	rm -rf $(objs)

%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

fclean:
	rm -rf $(objs) $(name) $(LIBNAME)
