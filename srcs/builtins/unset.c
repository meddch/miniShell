/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:15:28 by azari             #+#    #+#             */
/*   Updated: 2023/06/03 19:54:37 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	ft_delnode(t_env **env, char *var)
{
	t_env	*cur;
	t_env	*unset;

	cur = *env;
	unset = ft_srchenv(*env, var);
	if (!unset)
		return ;
	while (cur)
	{
		if (cur->next == unset)
		{
			cur->next = unset->next;
			free (unset);
		}
		cur = cur->next;
	}
}

void	unset(t_env **env, char **arg)
{
	int		i;

	i = 0;
	if (!env)
		return ;
	while (arg[++i])
	{
		if (ft_check_id(arg[i]) != 0)
			ft_delnode(env, arg[i]);
		else
			ft_printf_fd(2, "unset: `%s': not a valid identifier\n", arg[i]);
	}
}