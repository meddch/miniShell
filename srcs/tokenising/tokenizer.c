/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:31:31 by mechane           #+#    #+#             */
/*   Updated: 2023/05/05 12:04:07 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

int	whitespaces(t_lex *lex, char **line)
{
	char *cmd;
	
	cmd = *line;
	while (*cmd && ft_strchr(WHITESPACE, *cmd) && *cmd != '\n')
		cmd++;
	lex->spc = true;
	*line = cmd;
	return(0);
}
int	check_s_token(t_lex *lex, char **line)
{
	char *cmd;
	
	cmd = *line;
	(ft_strchr("|<>&", *cmd) && *cmd == *(cmd + 1)) && (lex->is_d = 1);
	(*cmd != '\'' && *cmd != '\"') && (lex->spc = true);
	(*cmd == '\"') && (lex->dq = !lex->dq); 
	(*cmd == '\'') && (lex->sq = !lex->sq);
	(*cmd == '(') && (lex->op = !lex->op);
	(*cmd == ')') && (lex->cp = !lex->cp);
	if (ft_strchr("|<>&", *cmd))
		add_back_tok(&lex->token , new_tok(token_flag(*cmd, lex->is_d),
			false, false, ft_strndup(cmd, (cmd + lex->is_d + 1))));
	else if ((lex->sq && *(cmd + 1)!= '\'') || (lex->dq && *(cmd + 1) != '\"'))
	{
		cmd++;
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
		(*cmd == '\"') && (lex->dq = !lex->dq); 
		(*cmd == '\'') && (lex->sq = !lex->sq);
	}
	cmd++;
	(lex->is_d) && (lex->is_d = 0) && cmd++;
	*line = cmd;
	return (0);
}

int check_w_token(t_lex *lex, char	**line)
{
	char *cmd;
	
	cmd = *line;
	if (lex->spc)
	{
		add_back_tok(&lex->token, new_tok(WORD, true, true, 
				get_word(&cmd)));
		lex->spc = false;
	}
	else if (!lex->spc)
	{
		lex->tmp = last_tok(lex->token);
		while (lex->tmp->sub)
			lex->tmp = lex->tmp->sub;
		lex->tmp->sub = new_tok(WORD, true, true, 
				get_word(&cmd));
	}
	*line = cmd;
	return(0);
}

t_token	*tokenizer(char *line)
{
	t_lex	lex;
	
	new_lex(&lex);
	while(*line && *line != '\n')
	{
		(ft_strchr(WHITESPACE, *line)) && whitespaces(&lex, &line);
		(ft_strchr("\"\'|<>&()", *line)) && check_s_token(&lex, &line);
		(!ft_strchr("\"\'|<>&() \t", *line) && (!lex.dq || !lex.sq))
			&& check_w_token(&lex, &line);
	}
	add_back_tok(&lex.token, new_tok(END, false, false, ft_strdup("END")));
	if (lex.sq || lex.dq)
		return (printf("Syntax Error : Quotes ?\n"), NULL);
	if (lex.cp != lex.op)
		return (printf("Syntax Error : Parenthesis ?\n"), NULL);
	return (lex.token);
}
 
t_token	*lexer(void)
{
	char *prompt = "(miniShell) $ ";
	char *lineptr;
    t_token *token;
		
	while (1)
	{
		lineptr = readline(prompt);
		if (!lineptr || !ft_strcmp(lineptr, "exit"))
    		return(free(lineptr), NULL);
		if (*lineptr)
		{
			add_history(lineptr);
			token = tokenizer(lineptr);	
		}
		
		while(token)
		{
			printf("token :/%s/  type : %d  xpand :%d\n", token->data,token->type,token->xpand);
			if (token->sub)
				printf("           sub : /%s/ type : %d xpand :%d\n", token->sub->data, token->sub->type, token->sub->xpand);
			token = token->next;
		}
		gc(0, 0);
	}
}

