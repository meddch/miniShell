/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:09:44 by azari             #+#    #+#             */
/*   Updated: 2023/06/02 14:32:48 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	ft_print_export(t_env *env)
{
	if (!env)
		return ;
	while (env)
	{
		if (env->val != NULL)
			printf("%s %s=\"%s\"\n", D_X, env->var, env->val);
		else
			printf("%s %s\n", D_X, env->var);
		env = env->next;
	}
}

int	ft_check_id(char *id)
{
	int	eq_index;

	eq_index = 1;
	if (id[0] != '_' && !ft_isalpha(id[0]))
		return (-1)	;
	while (id[eq_index] && id[eq_index] != '=')
	{
		if (!ft_isalnum(id[eq_index]) && id[eq_index] != '_')
			return (-1);
		eq_index++;
	}
	if (id[eq_index] == '=' && id[eq_index + 1])
		return (eq_index);
	return (0);
}

char	**ft_get_varval(char *arg)
{
	int		i;
	char	**varval;

	i = 0;
	varval = malloc(sizeof(char *) * 3);
	if (!varval)
		return (NULL);
	varval[0] = get_var(arg);
	if (ft_strchr(arg, '='))
		varval[1] = get_val(arg);
	else
		varval[1] = NULL;
	varval[2] = NULL;
	return (varval);
}

void	ft_add_front(t_env **env, t_env *new)
{
	t_env *tmp;
	
	tmp = *env;
	new->next = tmp;
	*env = new;
}

void	export(t_env **env, char **args)
{
	int		i;
	int		check;
	char	**node;
	t_env	*tmp;

	i = 0;
	if (!args[1])
		return (ft_print_export(*env));
	while (args[++i])
	{
		check = ft_check_id(args[i]);
		node = ft_get_varval(args[i]);
		if (check != -1)
		{
			tmp = ft_env_new(node[0], node[1]);
			ft_envadd_back(env, tmp);
		}
		else
			ft_printf_fd(2, "export: `%s': not a valid identifier\n", node[0]);
	}
}

