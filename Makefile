# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 15:50:40 by makpolat          #+#    #+#              #
#    Updated: 2025/03/02 16:00:55 by makpolat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	ft_strlen.c \
	ft_substr.c \
	ft_strdup.c \
	ft_split.c \
	ft_isdigit.c \
	ft_atoi.c \
	control.c \
	addlist.c \
	ft_atoilst.c \
	movements.c \
	pushswap_utils.c \
	algorithms.c \
	algorithms2.c \
	algorithms3.c

LIBC = ar rc

all: $(NAME)

$(NAME): $(SRC)
	${CC} $(CFLAGS) -o $(NAME) $(SRC) 

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re