/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:55:15 by mechane           #+#    #+#             */
/*   Updated: 2023/05/03 20:41:09 by mechane          ###   ########.fr       */
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
# include <stdbool.h>
# include "../libft/libft.h"

#define WHITESPACE " \t\r\n\v"
#define SYMBOLS "|&<>"

typedef enum s_flag
{
	WORD = 0,
	DQ = 1,
	SQ = 2,
	PIPE = 3,
	RIN = 4,
	ROUT = 5,
	OPAR = 6,
	CPAR = 7,
	SPACE = 8,
	AND = 9,
	OR = 10,
	HEREDOC = 11,
	APPEND = 12,
	SUBSHELL,
	REDIR,
	SIGHER,
	END,
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
	int			flag;
	t_token		*token;
	t_token		*sub;
	bool		spc;
	bool		h_doc;
	bool		dq;
	bool		sq;
	bool		op;
	bool		cp;
}	t_lex;

int		token_size(t_token *lst);
int		token_flag(char c, int flag);
int		add_back_tok(t_token **tok, t_token *new);
t_token	*new_tok(t_flag type, bool xpand, bool h_doc, char *word);
t_token	*last_tok(t_token *tok);
t_token	*last_sub_tok(t_token *tok);
t_lex	*new_lex();
char	*get_q_token(char **cmd, char q);
char	*get_word(char **cmd);
char	*getq(char *str, int *index, char c);
#endif