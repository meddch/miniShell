/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:33:04 by mechane           #+#    #+#             */
/*   Updated: 2023/05/29 13:43:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"


t_env	*ft_lstchr(t_env *lst, const char *variable)
{
	int	len;

	if (!lst)
		return (NULL);
	len = ft_strlen(variable);
	while (lst)
	{
		if (!ft_memcmp(lst->val, variable, len + 1))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

bool	is_builtin(char *cmd, char **argv)
{
	if (!ft_strncmp(cmd, "echo", sizeof("echo") + 1))
		return (echo(argv), true);
	else if (!ft_strncmp(cmd, "cd", sizeof("cd") + 1))
		return (cd(argv), true);
	else if (!ft_strncmp(cmd, "pwd", sizeof("pwd") + 1))
		return (pwd(argv), true);
	else if (!ft_strncmp(cmd, "export", sizeof("export") + 1))
		return (export(argv), true);
	else if (!ft_strncmp(cmd, "unset", sizeof("unset") + 1))
		return (unset(argv), true);
	else if (!ft_strncmp(cmd, "env", sizeof("env") + 1))
		return (ft_env(argv), true);
	else if (!ft_strncmp(cmd, "exit", sizeof("exit") + 1))
		return (ft_exit(argv), true);
	return (false);
}

void	exit_status(int status)
{
	if (WIFEXITED(status))
		g_st = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_st = 128 + WTERMSIG(status);
}

char	*get_cmd_path(char *arg, t_env *env)
{
	int		i;
	char	*new_arg;
	char	**paths;
	t_env	*tmp;

	i = -1;
	if (*arg == '/' || !access(arg, X_OK) || !*arg)
		return (arg);
	tmp = ft_lstchr(env, "PATH");
	if (!tmp)
		return (printf("%s: No such file or directory\n", arg), NULL);
	paths = ft_split(tmp->val, ':');
	while (paths[++i])
	{
		new_arg = ft_strjoin_sp(paths[i], arg, '/');
		if (!access(new_arg, X_OK))
			return (new_arg);
	}
	return (paths[0]);
}