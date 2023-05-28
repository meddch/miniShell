/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:47:05 by mechane           #+#    #+#             */
/*   Updated: 2023/05/28 11:06:50 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char	*expansion(t_env *env, char	*to_expand)
{
	char	*expanded;
	char	*tmp;
	
	expanded = NULL;
	if (!to_expand)
		return (NULL);
	while(*to_expand)
	{
		if (*to_expand == '$' && (*to_expand +1))
		{
			to_expand++;
			if (to_expand == '?')
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
}

void	exp_help(t_env *env, char *to_expand, t_token **expand)
{
	char	**hold;
	int		i;

	i = 0;
	hold = ft_split_set(expansion(env, to_expand), WHITESPACE);
	if (!hold[i])
		add_back_tok(expand, new_tok(WORD, 0, 0, ft_strdup("")));
	while (hold[i])
	{
		add_back_tok(expand, new_tok(WORD, 0, 0, hold[i]));
		i++;
	}
}

void	expand_sub(t_env *env, char *to_expand, t_token **expand, int dq_flag)
{
	t_token	*tmp;
	char	**hold;
	int		i;
	
	i = 0;
	tmp = NULL;
	if(!dq_flag)
	{	
		hold = ft_split_set(expansion(env, to_expand), WHITESPACE);
		if (!hold[i])
			add_back_sub(expand, new_tok(WORD, 0, 0, ft_strdup("")));
		while (hold[i])
		{
			add_back_sub(expand, new_tok(WORD, 0, 0, hold[i]));
			i++;
		}
	}
	else
		add_back_sub(&expand, new_tok(WORD, 0, 0,expansion(env, to_expand)));
	return (expand);
}


t_token	*expand_node(t_env	*env, char	*to_expand, int	dq_flag)
{
	t_token	*expand;
	
	expand = NULL;
	if(!dq_flag)
		exp_help(env, to_expand, &expand);
	else
		add_back_tok(&expand, new_tok(WORD, 0, 0,expansion(env, to_expand)));
	return (expand);
}