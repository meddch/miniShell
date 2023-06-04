/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:34:33 by mechane           #+#    #+#             */
/*   Updated: 2023/06/02 08:47:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char    *get_env_variable(t_env *env, char *var)
{
    t_env	*current;

	if (!env)
		return (NULL);
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
	tmp = var;
	if (!var || (!ft_isalpha(*var) && (*var) != '_'))
		return (NULL);
	var++;
	while (*var && ft_isalnum(*var))
		var++;
	(*to_check) = var;
	return (ft_strndup(tmp, var));
}

char	*get_non_var(char **to_check)
{
	char	*tmp;
	char	*hold;
	
	tmp = *to_check;
	while(*tmp && *tmp != '$')
		tmp++;
	hold = ft_strndup((*to_check), (tmp ));
	(*to_check) = tmp;
	return (hold);
}

char	*expand_var(char **var, t_env *env)
{
	char	*valid_var;

	valid_var = get_valid_var(var);
	if (!valid_var || !env)
		return (NULL);
	return (ft_strdup(get_env_variable(env, valid_var)));
}
