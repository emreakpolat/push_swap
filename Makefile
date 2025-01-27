NAME = pushswap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = pushswap.c \
	ft_strlen.c \
	ft_substr.c \
	ft_strdup.c \
	ft_split.c \
	ft_isdigit.c \
	ft_atoi.c \

OBJS = $(SRC:.c=.o)

LIBC = ar rc

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re