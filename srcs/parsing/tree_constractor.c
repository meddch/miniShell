/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_constractor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:54:26 by mechane           #+#    #+#             */
/*   Updated: 2023/05/14 11:50:22 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishel.h"

t_tree *constract_block(int type, t_tree *left, t_tree *right)
{
	t_connector *n;
	n = gc(sizeof(t_connector), 0);
	return(n->cmd_type = type, n->left = left, n->right = right, (t_tree *)n);
}
t_tree *constract_pipe(t_tree *left, t_tree *right)
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

t_tree	*new_redir(t_tree *tree)
{
	t_redir	*redir;

	redir = gc(sizeof(t_redir), 0);
	redir->cmd_type = REDIR;
	redir->cmdtree = tree;
	return ((t_tree *)redir);
}

