# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechane <mechane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 10:35:42 by mechane           #+#    #+#              #
#    Updated: 2023/05/05 16:04:02 by mechane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RED = \033[0;31m
BLUE = \033[0;34m
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT_H = libft.h

FILES_M = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_strndup \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_striteri \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_malloc \

FILES_B = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap

SRCS_M = $(addsuffix .c, $(FILES_M))
SRCS_B =$(addsuffix .c, $(FILES_B))

OBJS_M = $(addsuffix .o, $(FILES_M))
OBJS_B = $(addsuffix .o, $(FILES_B))


%.o : %.c $(LIBFT_H)
	@$(CC) $(CFLAGS) -c -o $@ $<
	
$(NAME): $(OBJS_M) 
	@$(AR) $@ $^
	@echo "$(BLUE)libft ✅"

bonus: $(OBJS_B)
	@$(AR) $(NAME) $^

all: $(NAME)

clean:
	@$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)

re: fclean all bonus

.PHONY: bonus all clean fclean re
	
