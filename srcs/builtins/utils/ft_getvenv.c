/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:28:09 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 22:51:39 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

char	*get_var(char *line)
{
	char	*var;
	size_t	i;

	i = 0;
	while (line[i] && line[i + 1] != '=')
		i++;
	if (line[i] == '+')
		var = ft_sub(line, 0, i);
	else
		var = ft_sub(line, 0, i + 1);
	return (var);
}

char	*get_val(char *line)
{
	char	*val;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	(line[i] == '=') && (i += 1);
	val = ft_sub(line, i, ft_strlen(line + i));
	return (val);
}

char	*ft_inc_shlvl(char *val)
{
	if (ft_atoi(val) == 999)
		return (free(val), ft_stdup(""));
	else if (ft_atoi(val) > 999)
	{
		ft_printf_fd(2, "warning: shell level (%d) too high, \
resetting to 1\n", ft_atoi(val) + 1);
		return (free(val), ft_stdup("1"));
	}
	else
		return (free(val), ft_stdup(ft_itoa(ft_atoi(val) + 1)));
}

t_env	*ft_getvenv(char **env)
{
	t_env	*virt;
	t_env	*node;
	char	*oval;
	int		i;

	virt = NULL;
	i = -1;
	if (!env || !*env)
	{
		ft_envadd_back(&virt, ft_env_new("PATH", PATH));
		ft_envadd_back(&virt, ft_env_new("SHLVL", "1"));
		return (virt);
	}
	while (env[++i])
		ft_envadd_back(&virt, ft_env_new(get_var(env[i]), get_val(env[i])));
	node = ft_srchenv(virt, SHLVL);
	oval = node->val;
	node->val = ft_inc_shlvl(oval);
	ft_delnode(&virt, OLDPWD);
	return (virt);
}
