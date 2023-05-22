# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechane <mechane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 10:35:42 by mechane           #+#    #+#              #
#    Updated: 2023/05/21 23:07:50 by mechane          ###   ########.fr        #
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


SRCS_M = $(addsuffix .c, $(FILES_M))
OBJS_M = $(addsuffix .o, $(FILES_M))


%.o : %.c $(LIBFT_H)
	@$(CC) $(CFLAGS) -c -o $@ $<
	
$(NAME): $(OBJS_M) 
	@$(AR) $@ $^
	@echo "$(BLUE)libft ✅"

all: $(NAME)

clean:
	@$(RM) $(OBJS_M) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all 

.PHONY:  all clean fclean re
	
