/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:55:15 by mechane           #+#    #+#             */
/*   Updated: 2023/05/03 13:41:34 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
#define TOKENIZER_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdbool.h>

#define WHITESPACE " \t\r\n\v"
#define SYMBOLS "|&<>"

typedef enum s_flag
{
	WORD = 97,
	DQ = 34,
	SQ = 39,
	PIPE = 124,
	RIN = 60,
	ROUT = 62,
	OPAR = 40,
	CPAR = 41,
	SPACE = 32,
	AND = 64,
	OR = 33,
	HEREDOC = 45,
	APPEND = 43,
	END = 0,
}	t_flag;

typedef struct s_token{
	struct s_token 	*next;
	struct s_token	*sub;
	char			*data;
	t_flag			type;
	bool			xpand;
	bool			h_doc;
}t_token;

typedef	struct s_lex{
	int 		i;
	t_token		*token;
	t_token		*sub;
	bool		space;
	bool		h_doc;
	bool		dq;
	bool		sq;
	bool		op;
	bool		cp;
}	t_lex;

char	*ft_strchr(const char *str, int c);
char	*ft_strdup( const char *source );
char	*ft_strndup(char *start, char *end);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s11, char *s22);
char	*ft_strtrim(char const *s1);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, int start, int len);
#endif