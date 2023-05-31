/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:18:15 by mechane           #+#    #+#             */
/*   Updated: 2023/05/29 13:45:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	apply_exp(t_token **token, t_env *env)
{
	t_token	*tmp;
	t_token *exp;
	
	tmp = *token;
	exp = NULL;
	while(tmp)
	{
		add_back_tok(&exp, expand_node(env, tmp->data, (tmp->h_doc == 0)));
		while(tmp->sub)
		{
			add_back_sub(&exp->sub, expand_sub(env, tmp->sub->data, (tmp->sub->h_doc == 0)));
			tmp->sub = tmp->sub->sub;
		}
		tmp = tmp->next;
	}
	(*token) = exp;
}

void 	apply_wc(t_token **token)
{
	t_token	*tmp;
	t_token *exp;
	
	tmp = *token;
	exp = NULL;
	while(tmp)
	{
		add_back_tok(&exp, expanand_wc(tmp->data));
		while(tmp->sub)
		{
			add_back_sub(&exp->sub, expanand_wc(tmp->sub->data));
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
	
	i = -1;
	cmdlist = tree->list;
	apply_exp(&cmdlist, env);
	apply_wc(&cmdlist);
	size = token_size(cmdlist);
	cmd = gc(sizeof(char *)*(size + 1), 0);
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

void	exec_cmd(t_cmd *tree, t_env *env)
{
	pid_t pid;
	char	**cmdline;
	char	*cmd;

	cmdline = get_cmdline(tree, env);
	if (is_builtin(cmdline[0], cmdline))
		return ;
	cmd = get_cmd_path(cmdline[0], env);
	pid = fork();
	//create ft_fork (protect)
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		execve(cmd, cmdline, env);
		printf("command not found: %s\n", cmdline[0]); //fd_printf 
	}
	waitpid(pid, &g_st, WUNTRACED);
}