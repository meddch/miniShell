/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:20:45 by mechane           #+#    #+#             */
/*   Updated: 2022/10/24 22:00:03 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cc;
	int		i;

	if (!lst)
		return (0);
	cc = lst ;
	i = 0;
	while (cc)
	{
		cc = cc->next;
		i++;
	}
	return (i);
}
