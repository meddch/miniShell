/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:15:28 by azari             #+#    #+#             */
/*   Updated: 2023/06/10 13:37:25 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	ft_delnode(t_env **env, char *var)
{
	t_env	*cur;
	t_env	*unset;

	cur = *env;
	unset = ft_srchenv(*env, var);
	if (!unset)
		return ;
	if (cur == unset)
	{	
		*env = cur->next;
		ft_free (unset->var);
		ft_free (unset->val);
		return (ft_free (unset));
	}
	while (cur)
	{
		if (cur->next == unset)
		{
			cur->next = unset->next;
			ft_free (unset->var);
			ft_free (unset->val);
			ft_free (unset);
		}
		cur = cur->next;
	}
}

int	ft_check(char *id)
{
	int	index;

	index = 1;
	if (!ft_isalpha(id[0]) && id[0] != '_')
		return (0);
	while (id[index] && (ft_isalnum(id[index]) || id[index] == '_'))
		index++;
	if (id[index])
		return (0);
	return (1);
}

void	unset(t_env **env, char **arg)
{
	int		i;

	i = 0;
	set_status(0);
	if (!env)
		return ;
	while (arg[++i])
	{
		if (ft_check(arg[i]) != 0)
			ft_delnode(env, arg[i]);
		else
		{
			ft_printf_fd(2, "unset: `%s': not a valid identifier\n", arg[i]);
			set_status(1);
		}
	}
}
