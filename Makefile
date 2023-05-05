CC = cc

NAME = minishell

CFLAGS = -Wall -Wextra -Werror 

HEADER =   /include/tokenizer.h ./include/minishell.h ./include/parser.h ./libft/libft.h

LIBFT = libft/libft.a

SRCS = main.c tokenising/tok_utils.c tokenising/utils.c tokenising/tokenizer.c

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