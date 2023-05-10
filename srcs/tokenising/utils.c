/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:58:06 by mechane           #+#    #+#             */
/*   Updated: 2023/05/09 13:45:31 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	new_lex(t_lex *lex)
{
	lex->spc = true;
	lex->h_doc = false;
	lex->dq = false;
	lex->sq = false;
	lex->op = false;
	lex->cp = false;
	lex->token = NULL;
	lex->tmp = NULL;
	lex->is_d = 0;
	return ;
}

int	token_flag(char c, int flag)
{
	char	*str;
	int		i;

	i = -1;
	str = "\"\'|<>()";
	while (str[++i])
		if (str[i] == c)
			break ;
	if (c == '&' && !flag)
		return (0);
	else if (c == '&' && flag)
		return (9);
	(flag) && (i += 7);
	return (i + 1);
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
	*cmd = (s );
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
	while (*cmd && ft_strchr(WHITESPACE, *cmd) && *cmd != '\n')
		cmd++;
	lex->spc = true;
	*line = cmd;
	return(0);
}
