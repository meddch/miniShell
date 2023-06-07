/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:30 by azari             #+#    #+#             */
/*   Updated: 2023/06/07 12:14:18 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_env	*ft_env_new(char *evar, char *eval, int flag)
{
	t_env		*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->var = ft_stdup(evar);
	new->val = ft_stdup(eval);
	new->def = 0;
	new->next = NULL;
	(flag) && (ft_free(eval), ft_free(evar), flag += 0);
	return (new);
}

int	ft_envsize(t_env *env)
{
	t_env	*cur;
	int		i;

	if (!env)
		return (0);
	cur = env;
	i = 1;
	while (cur->next)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

t_env	*ft_srchenv(t_env *env, char *var)
{
	if (!env)
		return (NULL);
	while (env)
	{
		if (!ft_strcmp(env->var, var))
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
