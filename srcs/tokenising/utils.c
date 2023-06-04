/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:58:06 by mechane           #+#    #+#             */
/*   Updated: 2023/06/03 12:48:31 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	new_lex(t_lex *lex)
{
	lex->spc = true;
	lex->h_doc = false;
	lex->dq = false;
	lex->sq = false;
	lex->token = NULL;
	lex->tmp = NULL;
	lex->is_d = 0;
	return ;
}


int	token_flag(char c, int flag)
{
	char	*str;
	int		i;

	i = 1;
	str = "\"\'|()<>";
	while (*str)
	{
		if (*str == c)
			break ;
		i++;
		str++;
	}
	if (c == '&' && !flag)
		return (WORD);
	else if (c == '&' && flag)
		return (AND);
	else if (c == '|' && flag)
		return (OR);
	else if (c == '>' && flag)
		return (APPEND);
	else if (c == '<' && flag)
		return (HEREDOC);
	return (1 << i);
}

char	*get_q_token(char **cmd, int flag)
{
	char	q;
	char	*s;
	char	*tok;
	
	s = *cmd;
	if (flag)
		q = '\"';
	else
		q = '\'';
	while (*s && *s != q)
		s++;
	tok = ft_strndup(*cmd, s);
	*cmd = s;
	return (tok);
}

char	*get_word(char **cmd)
{
	char	*s;
	char	*tok;
	s = *cmd;
	while (*s && !ft_strchr("\"\'|<>&() \t", *s))
		s++;
	tok = ft_strndup(*cmd, s);
	*cmd = s;
	return (tok);
}

int	whitespaces(t_lex *lex, char **line)
{
	char *cmd;
	
	cmd = *line;
	while (*cmd && ft_strchr(WHITESPACE, *cmd))
		cmd++;
	lex->spc = true;
	*line = cmd;
	return(0);
}
