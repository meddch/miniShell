/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:58:06 by mechane           #+#    #+#             */
/*   Updated: 2023/05/04 11:21:19 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishel.h"

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
char	*getq(char *str, int *index, char c)
{
	int	i;
	int	j;

	i = *index;
	j = i;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (*index = i - 1, ft_substr(str, j, i - j));
	return (*index = i - 1, ft_substr(str, j, i - j));
}
char	*get_q_token(char **cmd, char q)
{
	char	*s;
	char	*tok;
	int		i;
	
	i = 0;
	s = *cmd;
	while (s[i] && s[i] != q)
		i++;
	// if (*s)
		tok = ft_strndup(*cmd, (s + i));
	// else
	// 	tok = ft_strndup(*cmd, (s + i - 1));
	*cmd = (s + i);
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
