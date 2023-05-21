/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:52:28 by mechane           #+#    #+#             */
/*   Updated: 2023/05/21 22:00:37 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"


t_list	*new_list(void)
{
	t_list	*list;

	list = gc((sizeof(t_list)), 0);
	list->len = 0;
	list->top = NULL;
	list->bottom = NULL;
	return (list);
}

t_node	*new_node(t_flag type)
{
	t_node	*new;

	new = gc((sizeof(t_node)), 0);
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*push_front(t_list *list, t_flag type, char *val)
{
	t_node	*new;

	new = new_node(type);
	new->next = list->top;
	if (list->top)
		list->top->prev = new;
	else
		list->bottom = new;
	list->top = new;
	(list->len)++;
	return (new);
}

t_node	*push_back(t_list *list, t_flag type, char *val)
{
	t_node	*new;

	new = new_node(type);
	new->prev = list->bottom;
	if (list->bottom)
		list->bottom->next = new;
	else
		list->top = new;
	list->bottom = new;
	(list->len)++;
	return (new);
}

t_node	*insert_node(t_list *list, t_node *new, t_node *prev)
{
	if (!list)
		return (NULL);
	(list->len)++;
	new->prev = prev;
	new->next = prev->next;
	if (!prev || !prev->next)
	{
		if (prev == NULL)
			list->top = new;
		if (prev->next == NULL)
			list->bottom = new;
	}
	else
	{
		prev->next->prev = new;
		prev->next = new;
	}
	return (new);
}
