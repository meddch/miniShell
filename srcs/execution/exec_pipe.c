/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:22:22 by mechane           #+#    #+#             */
/*   Updated: 2023/05/31 19:44:50 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

pid_t	run_pipe(t_tree *tree,t_env *env, int fd[2], int node)
{
	pid_t		pid;
	int			end;
	int			file;

	(node == LEFT_NODE) && (end = WRITE_END);
	(node == LEFT_NODE) && (file = STDOUT_FILENO);
	(node == RIGHT_NODE) && (end = READ_END);
	(node == RIGHT_NODE) && (file = STDIN_FILENO);
	pid = fork();
	if (pid == -1)
		perror("Pipe failed");
	if (pid == 0)
	{
		(!close(file)) && (dup2(fd[end], file));
		(!close(fd[READ_END])) && (close(fd[WRITE_END]));
		exec(tree, env);
		exit(0);
	}
	return (pid);
}

void	exec_pipe(t_tree *tree, t_env *env)
{
	pid_t	pid[2];
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		return (perror("Pipe failed"));
	pid[0] = run_pipe(((t_connector *)tree)->left, env, fd, LEFT_NODE);
	if (!pid[0])
		return ;
	pid[1] = run_pipe(((t_connector *)tree)->right, env, fd, RIGHT_NODE);
	if (!pid[1])
		return ;
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	if (wait(&status) == pid[1])
		g_st = status;
}
