/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:47:05 by mechane           #+#    #+#             */
/*   Updated: 2023/06/12 10:24:44 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char	*expansion(t_env *env, char	*to_expand)
{
	char	*expanded;
	char	*tmp;

	if (!to_expand)
		return (NULL);
	expanded = NULL;
	while (*to_expand)
	{
		if (*to_expand == '$' && (*to_expand + 1))
		{
			to_expand++;
			if (*to_expand == '?')
			{
				tmp = ft_itoa(g_st);
				to_expand++;
			}
			else
				tmp = expand_var(&to_expand, env);
		}
		else
			tmp = get_non_var(&to_expand);
		expanded = ft_strjoin(expanded, tmp);
	}
	return (expanded);
}

void	exp_help(t_env *env, char *to_expand, t_token **expand)
{
	char	**hold;
	int		i;

	i = 0;
	hold = ft_split_set(expansion(env, to_expand), WHITESPACE);
	if (!hold || !hold[i])
		return ;
	while (hold[i])
	{
		add_back_tok(expand, new_tok(WORD, 0, 0, hold[i]));
		i++;
	}
}

t_token	*expand_sub(t_env *env, char *to_expand, int dq_flag)
{
	t_token	*expand;
	int		i;

	i = 0;
	expand = NULL;
	if (dq_flag)
		add_back_sub(&expand, new_tok(WORD, 0, 0, expansion(env, to_expand)));
	else
		add_back_sub(&expand, new_tok(WORD, 0, 0, ft_strdup(to_expand)));
	return (expand);
}

t_token	*expand_node(t_env *env, char *to_expand, int dq_flag, int h_doc)
{
	t_token	*expand;

	expand = NULL;
	if (!dq_flag)
		add_back_tok(&expand, new_tok(WORD, 0, 0, ft_strdup(to_expand)));
	else if (dq_flag && h_doc)
		exp_help(env, to_expand, &expand);
	else
		add_back_tok(&expand, new_tok(WORD, 0, 0, expansion(env, to_expand)));
	return (expand);
}
