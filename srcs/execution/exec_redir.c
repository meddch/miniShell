/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:52:19 by mechane           #+#    #+#             */
/*   Updated: 2023/06/01 20:53:31 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

int	xpand_h_doc(t_env *env, int fd_in)
{
	int		fd[2];
	char	*gnl;

	if (pipe(fd) == -1)
		return (perror("pipe"), exit(1), 0);
	gnl = expansion(env, get_next_line(fd_in));
	while (gnl)
	{
		write(fd[1], gnl, ft_strlen(gnl));
		free(gnl);
		gnl = expansion(env, get_next_line(fd_in));
	}
	return (close(fd[1]), fd[0]);
}

char	**get_filename(t_token *file, t_env *env)
{
	int		i;
	int		size;
	char	**file_name;
	
	i = 0;
	apply_exp(&file, env);
	apply_wc(&file);
	size = token_size(file);
	file_name = gc(sizeof(char *)*(size + 1), 0);
	while (file && file->type == WORD)
	{
		file_name[i] = ft_strdup(file->data);
		while (file->sub)
		{
			file_name[i] = ft_strjoin(file_name[i], file->sub->data);
			file->sub = file->sub->sub;
		}
		file = file->next;
		i++;
	}
	file_name[size] = NULL;
	return (file_name);
}


bool	dup_to(t_tree *tree, t_env *env, int flag)
{
	t_redir	*redir;
	int		fd;
	char	**file_name;
	int		to_dup;
	
	fd = 0;
	redir = (t_redir *)tree;
	to_dup = STDIN_FILENO;
	((redir->redir_type & (ROUT | APPEND))) && (to_dup = STDOUT_FILENO);
	if (redir->redir_type & (RIN | ROUT | APPEND))
	{
		file_name = get_filename(redir->file, env);
		if (file_name[1])
			return (ft_printf_fd(2, "ambiguous redirect\n"), false); // use fd_printf and exit(1)
		if ((fd = open(*file_name, redir->flags, 0664)) == -1)
			return (false); // create ft_open to handle error and fd_print error + exit(1)  // create ft-dup to handle error and exit(1)
		(flag == 0) && (dup2(fd, to_dup));
		close(fd);
		return (true);
	}
	if (redir->file->h_doc && !redir->file->sub)
		{
			fd = xpand_h_doc(env, redir->fd_in);
			dup2(fd, to_dup);// create ft-dup to handle error and exit(1)
		}
	else
		dup2(redir->fd_in, to_dup);
	return (true);
}



void	exec_redir(t_tree *tree, t_env *env)
{
	pid_t	pid;
	int		flag;
	
	flag = 0;
	pid = fork();
	if (pid == -1)
		return (perror("fork"));
	if (!pid)
	{
		while (tree && tree->node_type == NODE_REDIR)
		{
			if (dup_to(tree, env, flag) == false)
			{	
				tree = ((t_redir *)tree)->cmdtree;
				break ;
			}
			flag = 1;
			tree = ((t_redir *)tree)->cmdtree;
		}
		exec_cmd(((t_cmd *)tree), env);
		exit(0);
	}
	waitpid(pid, &g_st, 0);
}