NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra

SRCS =	push_swap.c \
		ft_algo.c \
		ft_verification.c \
		ft_initialization.c \
		ft_helper.c \
		ft_operation.c
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re



