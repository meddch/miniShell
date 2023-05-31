/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:31:31 by mechane           #+#    #+#             */
/*   Updated: 2023/05/29 11:46:55 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"


void	check_quotes(t_lex *lex, char **line)
{
	char *cmd;

	cmd = *line;
	if (lex->spc)
	{
		add_back_tok(&lex->token, new_tok(WORD, (lex->dq == true), false, 
				get_q_token(&cmd, (lex->dq == true))));
		lex->spc = false;
	}
	else if (!lex->spc)
	{
		lex->tmp = last_tok(lex->token);
		while (lex->tmp->sub)
			lex->tmp = lex->tmp->sub;
		lex->tmp->sub = new_tok(WORD, (lex->dq == true), false, 
						get_q_token(&cmd, (lex->dq == true)));
	}
	if (*cmd == '\"')
		lex->dq = !lex->dq; 
	if (*cmd == '\'')
		lex->sq = !lex->sq;
	*line = cmd;
}

void	check_symbols(t_lex *lex, char **line)
{
	char *cmd;
	
	cmd = *line;
	if (ft_strchr("|<>&", *cmd) && *cmd == *(cmd + 1))
		lex->is_d = 1;
	if (*cmd != '\'' && *cmd != '\"')
		lex->spc = true;
	if (*cmd == '\"')
		lex->dq = !lex->dq; 
	if (*cmd == '\'')
		lex->sq = !lex->sq;
	if (ft_strchr("|<>&()", *cmd))
		add_back_tok(&lex->token , new_tok(token_flag(*cmd, lex->is_d),
			false, false, ft_strndup(cmd, (cmd + lex->is_d + 1))));
	if (lex->is_d == 1)
	{
		lex->is_d = 0;		
		cmd++;
	}
	*line = cmd;
}

bool	check_syntax(t_lex *lex)
{
	t_token	*token;
	int		flag;

	token = lex->token;
	flag = 0;
	if (lex->sq || lex->dq)
		return (printf("%s Quotes ?\n", SYNTX), false);
	while (token)
	{
		if (flag < 0)
			return (printf("%s Parenthesis ?\n", SYNTX), false); //use fd_printf
		if (token->type == OPAR)
			flag++;
		else if (token->type == CPAR)
			flag--;
		token = token->next;
	}
	if (flag) 
		return (printf("%s Parenthesis ?\n", SYNTX), false);
	return (true);
}

t_token	*tokenizer(char *line)
{
	t_lex	lex;
	
	new_lex(&lex);
	while(*line && *line != '\n')
	{
		if (ft_strchr(WHITESPACE, *line))
			whitespaces(&lex, &line);
		else if (ft_strchr("\"\'|<>&()", *line))
			check_token(&lex, &line);
		else if (!ft_strchr("\"\'|<>&() \t", *line) && (!lex.dq || !lex.sq))
			check_w_token(&lex, &line);
	}
	add_back_tok(&lex.token, new_tok(END, false, false, ft_strdup("END")));
	if(!check_syntax(&lex))
		return (NULL);
	return (lex.token);
}

