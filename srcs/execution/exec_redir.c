/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:52:19 by mechane           #+#    #+#             */
/*   Updated: 2023/06/05 21:54:46 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

int	xpand_h_doc(t_env *env, int fd_in)
{
	int		fd[2];
	char	*line;

	ft_pipe(fd);
	line = expansion(env, get_next_line(fd_in));
	while (line)
	{
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = expansion(env, get_next_line(fd_in));
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


bool	dup_to(t_tree *tree, t_env *env, int *flag_in, int *flag_out)
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
			return (ft_printf_fd(2, "ambiguous redirect\n"), exit(1), false);
		fd = open(*file_name, redir->flags, 0664);
		if (fd == -1)
			return (ft_printf_fd(2, "%s : No such file or directory\n", *file_name), exit(1), false);
		if ((*(flag_in) == 1) && redir->redir_type == RIN)
			{
				ft_dup2(fd, to_dup);
				*flag_in = 0;
			}
		if ((*flag_out == 1) && redir->redir_type == ROUT)
			{
				ft_dup2(fd, to_dup);
				*flag_out = 0;
			}
		return (true);
	}
	if (redir->file->h_doc && !redir->file->sub)
		{
			fd = xpand_h_doc(env, redir->fd_in);
			return (ft_dup2(fd, to_dup), true);
		}
	return (dup2(redir->fd_in, to_dup), true);
}



void	exec_redir(t_tree *tree, t_env **env)
{
	pid_t	pid;
	int		flag_in;
	int		flag_out;
	int		status;
	
	flag_in = 1;
	flag_out = 1;
	pid = ft_fork();
	if (!pid)
	{
		while (tree && tree->node_type == NODE_REDIR)
		{
			if (dup_to(tree, *env, &flag_in, &flag_out) == false)
			{	
				tree = ((t_redir *)tree)->cmdtree;
				return ;
			}
			tree = ((t_redir *)tree)->cmdtree;
		}
		exec_cmd(((t_cmd *)tree), env);
		exit(0);
	}
	waitpid(pid, &status, 0);
	set_status(status);
}