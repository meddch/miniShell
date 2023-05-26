/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:47:05 by mechane           #+#    #+#             */
/*   Updated: 2023/05/26 14:24:08 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char	*expansion(t_env *env, char	*to_expand)
{
	
}


t_token	*expander(t_env	*env, char	*to_expand, int	dq_flag)
{
	t_token	*expand;
	
	expand = NULL;
	if(!dq_flag)
	{
		
	}
	add_back_tok(&expand, new_tok(WORD, 0, 0,expansion(env, to_expand)));
	return (expand);
}