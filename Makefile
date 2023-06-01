CC = cc
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
NAME = minishell
RM = rm -f
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g

HEADER =   include/tokenizer.h include/minishell.h include/parser.h libft/libft.h include/gc.h

LIBFT = libft/libft.a

FILE = main  srcs/tokenising/tok_utils  srcs/tokenising/utils  srcs/tokenising/tokenizer gc/gc \
	   srcs/tokenising/lexer  srcs/parsing/parser  srcs/parsing/list_utils  srcs/parsing/parser_utils \
	   srcs/parsing/tree_constractor   gnl/get_next_line   gnl/get_next_line_utils \
	   srcs/builtins/utils/ft_getvenv srcs/builtins/utils/struct_utils  srcs/builtins/utils/ft_sub \
	   srcs/builtins/utils/print_utils srcs/builtins/utils/ft_printf_fd \
	   srcs/builtins/ft_env srcs/builtins/echo \
	   srcs/execution/exec_cmd    srcs/execution/exec_oper   srcs/execution/exec_pipe   srcs/execution/exec_redir \
	   srcs/execution/exec_subsh  srcs/execution/exec_utils  srcs/execution/execution \
	   srcs/expansion/expand_wlc    srcs/expansion/expander      srcs/expansion/expander_utils \

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