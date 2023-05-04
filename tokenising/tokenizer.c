/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:31:31 by mechane           #+#    #+#             */
/*   Updated: 2023/05/03 22:18:18 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishel.h"

bool	all_whitespaces(char *cmd)
{
	int i;

	i = 0;
	while(cmd[i] && ft_strchr(WHITESPACE,cmd[i]))
		i++;
	if (i == ft_strlen(cmd))
		return true;
	return false;
}

int	check_s_token(t_lex *lex, char **line)
{
	char *cmd;
	
	cmd = *line;
	(*cmd == '"') && (lex->dq = !lex->dq); 
	(*cmd == '\'') && (lex->sq = !lex->sq);
	(ft_strchr("|<>&", *cmd) && *cmd == *(cmd + 1)) && (lex->flag = 1);
	(*cmd != '\'' && *cmd != '\"') && (lex->spc = true);
	(*cmd == '(') && (lex->op = !lex->op);
	(*cmd == ')') && (lex->cp = !lex->cp);
	if (!all_whitespaces(cmd) && !ft_strchr(WHITESPACE, *cmd))
	{
		add_back_tok(&lex->token , new_tok(token_flag(*cmd, lex->flag),
			false, false, ft_strndup(cmd, (cmd + lex->flag + 1))));
	}
	cmd++;
	if (*cmd && ft_strchr(WHITESPACE, *cmd))
	{
		while(*cmd && ft_strchr(WHITESPACE, *cmd))
			cmd++;
		cmd--;
	}
	(lex->flag) && cmd++;
	*line = cmd;
	return (0);
}

int check_q_token(t_lex *lex, char	**line)
{
	char *cmd;
	
	cmd = *line;
	if (lex->spc)
	{
		add_back_tok(&lex->token, new_tok(WORD, (lex->dq == true), false, 
				get_q_token(&cmd, *cmd)));
		lex->spc = false;
	}
	else if (!lex->spc)
	{
		lex->tmp = last_tok(lex->token);
		while (lex->tmp->sub)
			lex->tmp = lex->tmp->sub;
		lex->tmp->sub = new_tok(WORD, (lex->dq == true), false, 
				get_q_token(&cmd, *cmd));
	}
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
		lex.flag = 0;
		ft_strchr("\"\'|<>&() \t", *line) && check_s_token(&lex, &line);
		((lex.sq && *line != '\'') || (lex.dq && *line != '\"'))
			&& check_q_token(&lex, &line);
		(!ft_strchr("\"\'|<>&() \t", *line) && (!lex.dq || !lex.sq))
			&& check_w_token(&lex, &line);
	}
	add_back_tok(&lex.token, new_tok(END, false, false, ft_strdup("END")));
	return (lex.token);
}

int	main(int ac ,char **av, char **env)
{	
	char *prompt = "(miniShell) $ ";
	char *lineptr;
    t_token *token;
	
	
	(void)av,(void)env;
	if (ac != 1)
		return (1);
	while (1)
	{
		lineptr = readline(prompt);
		if (!lineptr || !ft_strcmp(lineptr, "exit"))
    		return(free(lineptr), 0);
		if (*lineptr)
		{
			add_history(lineptr);
			token = tokenizer(lineptr);	
		}
		while(token)
		{
			printf("token :/%s/\n",token->data);
			printf("type : %d\n",token->type);
			token = token->next;
		}
    }
}