/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:30 by azari             #+#    #+#             */
/*   Updated: 2023/06/02 14:25:23 by azari            ###   ########.fr       */
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

t_env	*ft_env_new(char *evar, char *eval)
{
	t_env		*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->var = evar;
	new->val = eval;
	new->def= 0; 
	new->next = NULL;
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
