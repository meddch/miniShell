/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:04:12 by mechane           #+#    #+#             */
/*   Updated: 2023/06/06 10:54:06 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

t_tree *parse_block(t_token **token)
{
	t_tree *tree;
	
	if (!(*token) || (*token)->type == END)
		return (NULL);
	tree = parse_pipeline(token);
	if (!tree)
		return (NULL);
	while((*token) && ((*token)->type & (AND | OR)))
	{
		((*token)->type == AND) && (tree = constract_block(NODE_AND, tree, NULL));
		((*token)->type == OR) && (tree = constract_block(NODE_OR, tree, NULL));
		*token = (*token)->next;
		((t_connector *)tree)->right = parse_pipeline(token);
		if(!((t_connector *)tree)->right)
			return (NULL);
	}
	return(tree);
}
t_tree *parse_pipeline(t_token **token)
{
	t_tree *tree;

	if (!(*token) || (*token)->type == END)
		return (NULL);
	tree = parse_sub(token);
	if (!tree)
		return (NULL);
	while((*token) && (*token)->type == PIPE)
	{
		*token = (*token)->next;
		tree = constract_pipe(tree, parse_sub(token));	
		if(!((t_connector *)tree)->right)
			return (NULL);
	}
	return(tree);
}


t_tree *parse_sub(t_token **token)
{
	t_tree *tree;

	if (!(*token) || (*token)->type == END)
		return (NULL);
	if ((*token) && (*token)->type == OPAR)
	{
		*token = (*token)->next;
		tree = constract_sub(parse_block(token));
		if(!((t_subsh *)tree)->subsh || (*token)->type != CPAR)
			return (NULL);
		*token = (*token)->next;
		return (parse_redir(tree, token));
	}
	return (parse_cmd(token));
}


t_tree	*parse_cmd(t_token **token)
{
	t_tree	*tree;
	t_cmd	*tmp;
	t_token *cpy_token;
	
	if (!(*token))
		return (NULL);
	tree = new_cmd();
	tmp = ((t_cmd *)tree);
	tree = parse_redir(tree, token);
	if (!tree)
		return (NULL);
	if (((*token)->type) == END)
		return (tree);
	if ((((*token)->type) != (WORD)) && (tree->node_type != NODE_REDIR))
		return (NULL);
	while ((*token) && (*token)->type == WORD)
	{
		cpy_token = copy_token(token);
		add_token_list(&(tmp->list), &cpy_token);
		tree = parse_redir(tree, token);
		if (!tree)
			return (NULL);
	}
	return (tree);
}



t_tree	*parser(t_token **token)
{
	t_tree	*tree;

	if (!*token || (*token)->type == END)
			return (NULL);
	tree = parse_block(token);
	if (!tree || (*token)->type != END)
	{
		if (!(((*token)->type) & (WORD | END | INTER_SIG)))
			ft_printf_fd(2, "syntax error near unexpected token `%s'\n", (*token)->data);
		else if ((*token)->type == INTER_SIG)
			return (NULL);
		else
			ft_printf_fd(2, "syntax error near unexpected token `newline'\n");
		set_status(258);
		return (NULL);
	}
	return (tree);
}
