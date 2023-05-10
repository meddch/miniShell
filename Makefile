CC = cc
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
NAME = minishell
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

HEADER =   include/tokenizer.h include/minishell.h include/parser.h libft/libft.h include/gc.h

LIBFT = libft/libft.a

FILE = main srcs/tokenising/tok_utils srcs/tokenising/utils srcs/tokenising/tokenizer gc/gc \
	   srcs/tokenising/lexer

SRCS = $(addsuffix .c, $(FILE))
OBJS = $(addsuffix .o, $(FILE))

%.o : %.c $(HEADER) 
	@echo "$(BLUE)Building project ⏳.."
	@ $(CC) $(CFLAGS) -c -o $@ $< 

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(LIBFT) -lreadline -o $(NAME) $^
	@echo "$(BLUE)minishell ✅"


clean:
	@make clean -C libft
	@$(RM) $(OBJS)
	@echo  "$(RED)OBJS DELETED ☠ "

fclean: clean 
	@$(RM) $(NAME) $(LIBFT)
	@echo  "$(RED)ALL DELETED ☠ "


re: fclean all 

sm : all clean

.PHONY: clean fclean re all