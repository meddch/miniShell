/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:58:51 by mechane           #+#    #+#             */
/*   Updated: 2023/06/02 10:45:37 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	exec_oper(t_tree *tree, t_env *env)
{
	exec(((t_connector *)tree)->left, env);
	if (tree->node_type == NODE_AND && !g_st)
		exec(((t_connector *)tree)->right, env);
	if (tree->node_type == NODE_OR && g_st)
		exec(((t_connector *)tree)->right, env);
}

void	ft_dup2(int dst, int src)
{
	close(src);
	if (dup2(dst, src) == -1)
		perror("dup2");
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	return (pid);
}

int	ft_pipe(int fd[2])
{
	int	ret;

	ret = pipe(fd);
	if (ret == -1)
		perror("pipe");
	return (ret);
}
