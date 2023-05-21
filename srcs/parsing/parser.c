/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:04:12 by mechane           #+#    #+#             */
/*   Updated: 2023/05/21 22:22:45 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

t_tree *parse_block(t_token **token)
{
	t_tree *tree;
	
	if ((*token)->type == END)
		return (tree);
	tree = parse_pipeline(token);
	while((*token)->type == AND || (*token)->type == OR)
	{
		tree = constract_block((*token)->type, tree, NULL);
		*token = (*token)->next;
		((t_connector *)tree)->right = parse_pipeline;
		if(!((t_connector *)tree)->right)
			return (NULL);
	}
	return(tree);
}
t_tree *parse_pipeline(t_token **token)
{
	t_tree *tree;

	if ((*token)->type == END)
		return (tree);
	tree = parse_redir(token);
	if (!tree)
		return (NULL);
	while((*token)->type == PIPE)
	{
		*token = (*token)->next;
		tree = constract_pipe(tree, parse_redir(token));	
		if(!((t_connector *)tree)->right)
			return (NULL);
	}
	return(tree);
}


t_tree *parse_sub(t_token **token)
{
	t_tree *tree;

	if ((*token)->type == END)
		return (tree);
	*token = (*token)->next;
	if ((*token)->type == OPAR)
	{
		*token = (*token)->next;
		tree = constract_sub(parse_block(token));
		if(!((t_subsh *)tree)->subsh || (*token)->type != CPAR)
			return(NULL);
	}
	*token = (*token)->next;
	return (tree);
}


t_tree	*parse_cmd(t_token **token)
{
	t_tree	*tree;
	t_cmd	*cmd;
	
	if ((*token)->type == END)
		return (tree);
	tree = ;
	cmd = ;
	if ((*token)->type == OPAR)
	{
		(*token)= (*token)->next;
		cmd = 
	}
}





t_tree	*parse_redir(t_token **token)
{
	t_tree	*tree;
	t_flag	redir_typ;

	if ((*token)->type == END)
		return (tree);
	tree = parse_command(token);
	while (((*token)->type) & REDIR)
	{
		redir_typ = (*token)->type;
		*token = (*token)->next;
		if (!((*token)->type & WORD))
			return (NULL);
		tree = new_redir(tree);
		if (!fill_redir((t_redir *)tree , redir_typ, *token))
			return (NULL);
		(*token)= (*token)->next;
	}
	return (tree);
}
