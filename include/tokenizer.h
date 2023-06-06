/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:55:15 by mechane           #+#    #+#             */
/*   Updated: 2023/06/06 16:43:54 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# define SYNTX "Syntax Error :"
# define WHITESPACE " \t\r\v\n"
# define SYMBOLS "|&<>"

typedef enum e_flag
{
	WORD = 1 << 0,
	DQ = 1 << 1,
	SQ = 1 << 2,
	PIPE = 1 << 3,
	OPAR = 1 << 4,
	CPAR = 1 << 5,
	RIN = 1 << 6,
	ROUT = 1 << 7,
	SPC = 1 << 8,
	AND = 1 << 9,
	OR = 1 << 10,
	HEREDOC = 1 << 11,
	APPEND = 1 << 12,
	SUBSHELL = 1 << 16,
	REDIR = (RIN | ROUT | APPEND| HEREDOC),
	END = 1 << 15,
	INTER_SIG = 1 << 20,
}	t_flag;

typedef struct s_token{
	struct s_token	*next;
	struct s_token	*sub;
	char			*data;
	t_flag			type;
	bool			xpand;
	bool			h_doc;
}t_token;

typedef struct s_lex
{
	int			is_d;
	t_token		*token;
	t_token		*tmp;
	bool		spc;
	bool		h_doc;
	bool		dq;
	bool		sq;
}	t_lex;

int		token_size(t_token *lst);
int		token_flag(char c, int flag);
int		add_back_tok(t_token **tok, t_token *new);
int		whitespaces(t_lex *lex, char **line);
char	*get_q_token(char **cmd, int flag);
char	*get_word(char **cmd);
int		check_w_token(t_lex *lex, char	**line);
void	new_lex(t_lex *lex);
int		check_token(t_lex *lex, char **line);
void	check_quotes(t_lex *lex, char **line);
void	check_symbols(t_lex *lex, char **line);
t_token	*lexer(void);
t_token	*new_tok(t_flag type, bool xpand, bool h_doc, char *word);
t_token	*last_tok(t_token *tok);
t_token	*last_sub_tok(t_token *tok);
int		add_back_sub(t_token **tok, t_token *new);
t_token	*tokenizer(char *line);

#endif