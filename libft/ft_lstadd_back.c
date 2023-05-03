/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:46:22 by mechane           #+#    #+#             */
/*   Updated: 2022/10/25 09:38:03 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*count;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	count = *lst;
	while (count->next)
		count = count->next;
	count->next = new;
}
