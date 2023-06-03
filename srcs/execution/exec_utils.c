/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:33:04 by mechane           #+#    #+#             */
/*   Updated: 2023/06/03 14:00:04 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"


t_env	*ft_lstchr(t_env *lst, char *variable)
{
	int	len;

	if (!lst)
		return (NULL);
	len = ft_strlen(variable);
	while (lst)
	{
		if (!ft_memcmp(lst->var, variable, len + 1))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

bool	is_builtin(char *cmd, char **argv, t_env **env)
{
	if (!ft_strncmp(cmd, "echo", ft_strlen("echo")))
		return (echo(argv), true);
	// else if (!ft_strncmp(cmd, "cd", ft_strlen("cd") + 1))
	// 	return (cd(argv), true);
	else if (!ft_strncmp(cmd, "pwd", ft_strlen("pwd") + 1))
		return (pwd(), true);
	else if (!ft_strncmp(cmd, "export", ft_strlen("export") + 1))
		return (export(env, argv), true);
	else if (!ft_strncmp(cmd, "unset", ft_strlen("unset") + 1))
		return (unset(env, argv), true);
	else if (!ft_strncmp(cmd, "env", ft_strlen("env") + 1))
		return (ft_env(*env), true);
	// else if (!ft_strncmp(cmd, "exit", ft_strlen("exit") + 1))
	// 	return (ft_exit(argv), true);
	return (false);
}



char	*get_cmd_path(char *arg, t_env *env)
{
	int		i;
	char	*new_arg;
	char	**paths;
	t_env	*tmp;

	i = -1;
	if (!arg)
		return (NULL);
	if (*arg && *arg == '/' && !access(arg, X_OK))
		return (arg);
	tmp = ft_lstchr(env, "PATH");
	if (!tmp)
		return (ft_printf_fd(2, "%s : No such file or directory\n", arg), NULL);
	paths = ft_split(tmp->val, ':');
	while (paths[++i])
	{
		new_arg = ft_strjoin_sp(paths[i], arg, '/');
		if (!access(new_arg, X_OK))
			return (new_arg);
	}
	return (paths[0]);
}