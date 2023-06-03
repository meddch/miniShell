/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:15:28 by azari             #+#    #+#             */
/*   Updated: 2023/06/03 11:28:42 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	ft_delnode(t_env **env, char *var)
{
	t_env	*cur;
	t_env	*fr;

	cur = *env;
	while (cur->next)
	{
		if (cur->next->var == var && cur->next->next)
		{
			fr = cur->next;
			cur->next = cur->next->next;
			free(fr);
		}
		else
			cur = cur->next;
	}
}

int	checker(char *id)
{
	int	i;

	i = 0;
	if (!ft_isalpha(id[0]) && id[0] != '_')
		return (-1);
	i++;
	while (id[i] && (ft_isalnum(id[i]) || id[i] == '_'))
		i++;
		if (!id[i])
		return (1);
	return (0);
}

void	unset(t_env **env, char **arg)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (arg[i])
	{
		if (checker(arg[i]))
			ft_delnode(env, arg[i]);
		else
			ft_printf_fd(2, "unset: `%s': not a valid identifier\n", arg[i]);
		i++;
	}
}
