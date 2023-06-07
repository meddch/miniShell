/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:18:15 by mechane           #+#    #+#             */
/*   Updated: 2023/06/07 12:05:37 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	apply_exp(t_token **token, t_env *env)
{
	t_token	*tmp;
	t_token	*exp;

	tmp = *token;
	exp = NULL;
	while (tmp && (tmp->type == WORD))
	{
		add_back_tok(&exp, expand_node(env, tmp->data,
				((tmp->xpand == 1)), (tmp->h_doc == 1)));
		while (tmp->sub)
		{
			add_back_sub(&exp, expand_sub(env, tmp->sub->data,
					(tmp->sub->xpand == 1)));
			tmp->sub = tmp->sub->sub;
		}
		tmp = tmp->next;
	}
	(*token) = exp;
}

void	apply_wc(t_token **token)
{
	t_token	*tmp;
	t_token	*exp;

	tmp = *token;
	exp = NULL;
	while (tmp && (tmp->type == WORD))
	{
		add_back_tok(&exp, expanand_wc(tmp->data));
		while (tmp->sub)
		{
			add_back_sub(&exp, expanand_wc(tmp->sub->data));
			tmp->sub = tmp->sub->sub;
		}
		tmp = tmp->next;
	}
	(*token) = exp;
}

char	**get_cmdline(t_cmd *tree, t_env *env)
{
	t_token	*cmdlist;
	char	**cmd;
	int		i;
	int		size;

	i = 0;
	cmdlist = tree->list;
	apply_exp(&cmdlist, env);
	apply_wc(&cmdlist);
	size = token_size(cmdlist);
	cmd = gc(sizeof(char *) * (size + 1), 0);
	while (cmdlist)
	{
		cmd[i] = ft_strdup(cmdlist->data);
		while (cmdlist->sub)
		{
			cmd[i] = ft_strjoin(cmd[i], cmdlist->sub->data);
			cmdlist->sub = cmdlist->sub->sub;
		}
		cmdlist = cmdlist->next;
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

void	exec_cmd(t_cmd *tree, t_env **env)
{
	pid_t	pid;
	char	**cmdline;
	char	*cmd;
	int		status;

	cmdline = get_cmdline(tree, *env);
	if (!cmdline || is_builtin(cmdline[0], cmdline, env))
		return ;
	cmd = get_cmd_path(cmdline[0], *env);
	if (!cmd)
		return ;
	pid = ft_fork();
	sig_ch(pid);
	if (pid == 0)
	{
		execve(cmd, cmdline, switch_env(*env));
		if (is_dir(cmdline[0]) == true)
			exit(126);
		ft_printf_fd(2, " %s : command not found\n", cmdline[0]);
		exit(127);
	}
	if (wait(&status) == pid)
		check_status(status);
	(status == SIGQUIT) && (ft_putendl_fd("Quit: 3", STDOUT_FILENO));
	(status == SIGINT) && (ft_putendl_fd("", STDOUT_FILENO));
}
