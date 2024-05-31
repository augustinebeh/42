# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 16:34:10 by abeh              #+#    #+#              #
#    Updated: 2024/05/19 16:34:10 by abeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c			\
		ft_memmove.c 		\
		ft_isalpha.c 		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strrchr.c		\
		ft_striteri.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_strjoin.c 		\
		ft_strtrim.c		\
		ft_strmapi.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strlen.c			\
		ft_strchr.c			\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_strdup.c			\
		ft_substr.c			\
		ft_split.c			\
		ft_itoa.c			

SRCSBONUS =	ft_lstnew.c		\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c		\

NAME = libft.a

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSBONUS:.c=.o)

INCLUDES = libft.h

CC = cc

CC_FLAGS = -Wall -Wextra -Werror


$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Libft Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(OBJSB)
	@ar rcs $(NAME) $(OBJS) $(OBJSB)

.PHONY: clean fclean re all bonus