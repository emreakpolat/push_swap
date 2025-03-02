NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = push_swap.c \
	ft_strlen.c \
	ft_substr.c \
	ft_strdup.c \
	ft_split.c \
	ft_isdigit.c \
	ft_atoi.c \
	ft_strcmp.c \
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
	cc   -o$(NAME) $(CFLAGS) $(SRC) 

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re