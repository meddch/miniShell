CC = cc

NAME = minishell

CFLAGS = -Wall -Wextra -Werror 

HEADER =   include/tokenizer.h include/minishell.h include/parser.h libft/libft.h include/gc.h

LIBFT = libft/libft.a

SRCS = main.c srcs/tokenising/tok_utils.c srcs/tokenising/utils.c srcs/tokenising/tokenizer.c gc/gc.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) -lreadline -o $(NAME) $^

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME) $(LIBFT)

re: fclean all 

.PHONY: clean fclean re all