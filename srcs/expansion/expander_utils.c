/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:34:33 by mechane           #+#    #+#             */
/*   Updated: 2023/05/27 18:43:13 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char *get_variable(t_env *env, char *var)
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
