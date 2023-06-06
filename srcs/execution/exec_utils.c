/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:33:04 by mechane           #+#    #+#             */
/*   Updated: 2023/06/06 14:18:37 by mechane          ###   ########.fr       */
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
	if (!ft_strcmp(cmd, "echo"))
		return (echo(argv), true);
	else if (!ft_strcmp(cmd, "cd"))
		return (cd(env ,argv), true);
	else if (!ft_strcmp(cmd, "pwd"))
		return (pwd(), true);
	else if (!ft_strcmp(cmd, "export"))
		return (export(env, argv), true);
	else if (!ft_strcmp(cmd, "unset"))
		return (unset(env, argv), true);
	else if (!ft_strcmp(cmd, "env"))
		return (ft_env(*env), true);
	else if (!ft_strcmp(cmd, "exit"))
		return (ft_exit(), true);
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
		return (set_status(127), ft_printf_fd(2, "%s : No such file or directory\n", arg), NULL);
	paths = ft_split(tmp->val, ':');
	while (paths[++i])
	{
		new_arg = ft_strjoin_sp(paths[i], arg, '/');
		if (!access(new_arg, X_OK))
			return (new_arg);
	}
	return (paths[0]);
}
char	**switch_env(t_env *myenv)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = ft_envsize(myenv);
	env = gc(sizeof(char *) * (len + 1), 0);
	env[len] = 0;
	while (myenv)
	{
		(env[i++] = ft_strjoin_sp(myenv->var,
					myenv->val, '='));
		myenv = myenv->next;
	}
	return (env);
}
bool	is_dir(char	*file)
{
	struct stat path_stat;
	stat(file, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
		return (ft_printf_fd(2, " %s : is a directory\n", file), true);
	return (false);
}
