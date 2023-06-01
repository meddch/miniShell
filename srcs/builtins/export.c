/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:09:44 by azari             #+#    #+#             */
/*   Updated: 2023/06/01 14:21:23 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	export_print(t_env* env)
{
	if (!env)
		return ;
	while (env)
	{
		if (env->def)
			ft_printf_fd(1, "%s %s=\"%s\"\n", D_X, env->var, env->val);
		env = env->next;
	}
}

void	export(t_env **env, char **args)
{
	int	i;

	i = 0;
	if (!args[1])
	{
		export_print(*env);
		return ;
	}
	while (args[++i])
	{
		
	}
	// check arg name and value with 1 equal only
}