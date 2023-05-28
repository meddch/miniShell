/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:34:33 by mechane           #+#    #+#             */
/*   Updated: 2023/05/28 11:06:56 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char *get_env_variable(t_env *env, char *var)
{
    t_env	*current;

    current = env;
	while (current)
	{
        if (!ft_strcmp(current->var, var))
			return (current->val);
        current = current->next;
    }
    return (NULL);
}

char	*get_valid_var(char **to_check)
{
	char	*var;
	char	*tmp;
	
	var = *to_check;
	if (!var || (!ft_isalpha(var) && (var) != '_'))
		return (NULL);
	var++;
	tmp = var;
	while (*var && ft_isalnum(*var))
		var++;
	(*to_check) = var;
	return (ft_strndup(tmp, (*var - 1)));
}

char	*get_non_var(char **to_check)
{
	char	*tmp;
	
	tmp = *to_check;
	while(*tmp && *tmp != '$')
		tmp++;
	(*to_check) = tmp;
	return (ft_strndup((*to_check), (*tmp + 1)));
}

char	*expand_var(char **var, t_env *env)
{
	char	*valid_var;

	valid_var = get_valid_var(var);
	if (!valid_var)
		return (NULL);
	return (ft_strdup(get_env_variable(env, valid_var)));
}
