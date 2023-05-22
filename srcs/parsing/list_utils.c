/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:52:28 by mechane           #+#    #+#             */
/*   Updated: 2023/05/22 16:45:07 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"


t_token	*copy_token(t_token **tok)
{
	t_token	*copy;

	copy = new_tok(0, 0, 0, NULL);
	copy->type = (*tok)->type;
	copy->h_doc = (*tok)->h_doc;
	copy->data = (*tok)->data;
	copy->xpand = (*tok)->xpand;
	copy->type = (*tok)->type;
	copy->sub = (*tok)->sub;
	copy->next = NULL;
	*tok = (*tok)->next;
	return (copy);
}

void	add_token_list(t_tree *cmd_list, t_token **token)
{
	t_token	*last;
	if (!(((t_cmd*)cmd_list)->list))
	{
		((t_cmd *)cmd_list)->list = copy_token(token);
		return ;
	}
	last = last_tok(((t_cmd *)cmd_list)->list);
	last->next = copy_token(token);
}