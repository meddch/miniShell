/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:09:44 by azari             #+#    #+#             */
/*   Updated: 2023/06/05 20:53:43 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

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
	int	index;

	index = 1;
	if (!ft_isalpha(id[0]) && id[0] != '_')
		return (0);
	while (id[index] && (ft_isalnum(id[index]) || id[index] == '_'))
		index++;
	if (id[index] == '+' && id[index + 1] == '=' && ft_strchr(id, '='))
		return (-1);
	if (id[index] == '=')
		return (1);
	return (1);
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

void	ft_export_node(t_env **env, char **node, int def, int flag)
{
	t_env	*srch;
	char	*oval;

	srch = ft_srchenv(*env, node[0]);
	if (srch && def == 0)
		return (free(node[0]), free(node[1]));
	if (!srch)
		return (ft_envadd_back(env, ft_env_new(node[0], node[1])));
	oval = srch->val;
	free(node[0]);
	if (!flag)
		return (srch->val = node[1], free(oval));
	return (srch->val = ft_join(oval, node[1]), (void)0);
}

void	export(t_env **env, char **args)
{
	int		i;
	int		check;
	char	**node;

	i = 0;
	if (!args[1])
		return (ft_print_export(*env));
	while (args[++i])
	{
		check = ft_check_id(args[i]);
		node = ft_get_varval(args[i]);
		if (!check)
			{
				set_status(1);
				ft_printf_fd(2, "export: `%s': not a valid identifier\n", args[i]);
			}
		else if (check == -1)
			ft_export_node(env, node, 1, 1);
		else if (check && !ft_strchr(args[i], '='))
			ft_export_node(env, node, 0, 0);
		else if (check && ft_strchr(args[i], '='))
			ft_export_node(env, node, 1, 0);
		free (node);
	}
}
