/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:58:06 by mechane           #+#    #+#             */
/*   Updated: 2023/05/03 20:55:28 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishel.h"

t_lex	*new_lex()
{
	t_lex	*lex;
	
	lex = malloc(sizeof(t_lex));
	lex->spc = false;
	lex->h_doc = false;
	lex->dq = false;
	lex->sq = false;
	lex->op = false;
	lex->cp = false;
	return (lex);
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

char	*get_q_token(char **cmd, char q)
{
	char	*s;
	char	*tok;
	s = *cmd;
	while (*s && *s != q)
		s++;
	if (*s)
		tok = ft_strndup(*cmd, (s + 1));
	else
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
	if (*s)
		tok = ft_strndup(*cmd, s + 1);
	else
		tok = ft_strndup(*cmd, s);
	*cmd = s;
	return (tok);
}
