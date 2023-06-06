/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:00:10 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 20:00:45 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

char	*ft_getpath(t_env *env, char *var)
{
	t_env	*path;

	path = ft_srchenv(env, var);
	if (!path)
		return (NULL);
	return (path->val);
}

void	ft_update_paths(t_env **env, char *var, char *val)
{
	t_env	*node;
	char	*del;

	if (!val)
		return ;
	node = ft_srchenv(*env, var);
	if (!node)
		return (ft_envadd_back(env, ft_env_new(var, val)));
	del = node->val;
	node->val = ft_stdup(val);
}

void	ft_runcd(t_env **env, char *path, char *err_str, int flag)
{
	char	*pwd;
	int		cd;

	if (!path)
		return (ft_printf_fd(2, "cd: %s not set\n", err_str), set_status(1));
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		chdir(path);
		ft_update_paths(env, PWD, getcwd(NULL, 0));
		ft_update_paths(env, OLDPWD, pwd);
		return (set_status(1), ft_printf_fd(2, "cd: error \
retrieving current directory: getcwd: cannot access\
  parent directories: No such file or directory\n"));
	}
	cd = chdir(path);
	if (cd == -1 && !flag)
		return (set_status(1), perror(path));
	if (flag < 0)
		printf("%s\n", path);
	ft_update_paths(env, PWD, getcwd(NULL, 0));
	ft_update_paths(env, OLDPWD, pwd);
}

void	cd(t_env **env, char **args)
{
	set_status(0);
	if (!env)
		return ;
	if (!args[1] || !ft_strcmp(args[1], "~"))
		return (ft_runcd(env, ft_getpath(*env, HOME), HOME, 1));
	if (!ft_strcmp(args[1], "-"))
		return (ft_runcd(env, ft_getpath(*env, OLDPWD), OLDPWD, -1));
	return (ft_runcd(env, args[1], args[1], 0));
}
