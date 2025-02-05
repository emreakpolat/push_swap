NAME = pushswap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = pushswap.c \
	ft_strlen.c \
	ft_substr.c \
	ft_strdup.c \
	ft_split.c \
	ft_isdigit.c \
	ft_atoi.c \
	ft_strcmp.c \



LIBC = ar rc

all: $(NAME)

$(NAME): $(SRC)
	cc -o $(NAME) $(CFLAGS) $(SRC) 

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re