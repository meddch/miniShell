/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_constractor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:54:26 by mechane           #+#    #+#             */
/*   Updated: 2023/05/23 11:42:32 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishel.h"

t_tree	*constract_block(int type, t_tree *left, t_tree *right)
{
	t_connector *n;
	n = gc(sizeof(t_connector), 0);
	return(n->node_type = type, n->left = left, n->right = right, (t_tree *)n);
}

t_tree	*constract_pipe(t_tree *left, t_tree *right)
{
	t_connector *n;
	n = gc(sizeof(t_connector), 0);
	return(n->node_type = NODE_PIPE, n->left = left, n->right = right, (t_tree *)n);
}

t_tree	*constract_sub(t_tree *tree)
{
	t_subsh	*sub;

	sub = gc(sizeof(t_subsh), 0);
	sub->node_type = NODE_SUBSH;
	sub->subsh = tree;
	return ((t_tree *)sub);
}

t_tree	*new_redir(t_tree *tree)
{
	t_redir	*redir;

	redir = gc(sizeof(t_redir), 0);
	redir->node_type = NODE_REDIR;
	redir->cmdtree = tree;
	redir->file = NULL;
	return ((t_tree *)redir);
}

t_tree	*new_cmd(void)
{
	t_cmd		*cmd;

	cmd = gc(sizeof(t_cmd), 0);
	if (!cmd)
		return (NULL);
	cmd->node_type = NODE_CMD;
	cmd->list = NULL;
	return ((t_tree *)cmd);
}

