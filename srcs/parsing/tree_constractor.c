/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_constractor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:54:26 by mechane           #+#    #+#             */
/*   Updated: 2023/05/20 13:16:27 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishel.h"

t_tree	*constract_block(int type, t_tree *left, t_tree *right)
{
	t_connector *n;
	n = gc(sizeof(t_connector), 0);
	return(n->cmd_type = type, n->left = left, n->right = right, (t_tree *)n);
}
t_tree	*constract_pipe(t_tree *left, t_tree *right)
{
	t_connector *n;
	n = gc(sizeof(t_connector), 0);
	return(n->cmd_type = PIPE, n->left = left, n->right = right, (t_tree *)n);
}

t_tree	*constratct_sub(t_tree *tree)
{
	t_subsh	*sub;

	sub = gc(sizeof(t_subsh), 0);
	sub->cmd_type = SUBSHELL;
	sub->subsh = tree;
	return ((t_tree *)sub);
}

t_redir	*new_redir(t_tree *tree)
{
	t_redir	*redir;

	redir = gc(sizeof(t_redir), 0);
	redir->redir_type = REDIR;
	redir->cmdtree = tree;
	return ((t_tree *)redir);
}

t_tree	*new_cmd(t_token *cmd_list)
{
	t_token		*tmp;
	t_cmd		*cmd;

	cmd = gc(sizeof(cmd), 0);
	if (!cmd)
		return (NULL);
	cmd->cmd_type = WORD;
	cmd->cmd = cmd_list;
	tmp = cmd_list;
	while (tmp->next->type == WORD && tmp->next->type != END)
		tmp = tmp->next;
	tmp->next = NULL;
	return ((t_tree *)cmd);
}