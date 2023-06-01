/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:57:22 by mechane           #+#    #+#             */
/*   Updated: 2023/06/01 15:37:33 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../../include/minishel.h"



void print_token(t_token *token)
{
    if (!token)
        return;
    while(token)
    {
        printf(" token type %d\n   token data : %s\n",token->type, token->data);
        token = token->next;
    }
}

int	check_token(t_lex *lex, char **line)
{
	char *cmd;
	
	cmd = *line;
	check_symbols(lex, &cmd);
	if ((lex->sq && *(cmd + 1)!= '\'') || (lex->dq && *(cmd + 1) != '\"'))
	{
		cmd++;
		check_quotes(lex, &cmd);
	}
	else if (((lex->sq && *(cmd + 1) == '\'') || (lex->dq && *(cmd + 1) == '\"')) && lex->spc)
	{
		cmd++;
		if ( *(cmd + 1) && ft_strchr(WHITESPACE, *(cmd + 1)))
			add_back_tok(&lex->token, new_tok(WORD, false, false, ft_strdup("")));
		if (*cmd == '\"')
			(lex->dq = !lex->dq); 
		if (*cmd == '\'')
			(lex->sq = !lex->sq);
	}
	cmd++;
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


