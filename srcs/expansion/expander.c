/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:47:05 by mechane           #+#    #+#             */
/*   Updated: 2023/05/26 15:50:50 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char	*expansion(t_env *env, char	*to_expand)
{
	
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

t_token	*expander(t_env	*env, char	*to_expand, int	dq_flag)
{
	t_token	*expand;
	
	expand = NULL;
	if(!dq_flag)
		exp_help(env, to_expand, &expand);
	add_back_tok(&expand, new_tok(WORD, 0, 0,expansion(env, to_expand)));
	return (expand);
}