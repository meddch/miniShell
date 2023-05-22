/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:11:16 by mechane           #+#    #+#             */
/*   Updated: 2023/05/22 19:28:44 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

t_token	*new_tok(t_flag type, bool xpand, bool h_doc, char *word)
{
	t_token	*tok;

	tok = gc(sizeof(t_token), 0);
	tok->data = word;
	tok->type = type;
	tok->next = NULL;
	tok->sub = NULL;
	tok->xpand = false;
	tok->h_doc = false;
	if (xpand)
		(tok->xpand = true);
	if (h_doc)
		(tok->h_doc = true);
	return (tok);
}

int	token_size(t_token *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_token	*last_tok(t_token *tok)
{
	
	if (!tok)
		return (NULL);
	while (tok->next)
	{
		
		tok = tok->next;
	}
	return (tok);
}

int	add_back_tok(t_token **tok, t_token *new)
{
	if (!tok)
		return (0);
	if (!*tok)
	{
		*tok = new;
		return (0);
	}
	last_tok(*tok)->next = new;
	new->next = NULL;
	return (0);
}

t_token	*last_sub_tok(t_token *tok)
{
	while (tok)
	{
		if (tok->sub == NULL)
			break ;
		tok = tok->sub;
	}
	return (tok);
}
