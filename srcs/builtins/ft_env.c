/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:53:22 by azari             #+#    #+#             */
/*   Updated: 2023/06/03 13:51:30 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	ft_env(t_env *virt)
{
	
	if (!virt)
		return ;
	while (virt)
	{
		if (virt->val != NULL)
			printf("%s=%s\n", virt->var, virt->val);
		virt = virt->next;
	}
}
