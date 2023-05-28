/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subsh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:34:59 by mechane           #+#    #+#             */
/*   Updated: 2023/05/28 17:35:22 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	exec_subsh(t_tree *tree, t_env *env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (perror("fork"));
	if (!pid)
	{
		exec(((t_subsh *)tree)->subsh, &env);
		exit(g_st);
	}
	waitpid(pid, &status, WUNTRACED);
	exit_status(status);
}