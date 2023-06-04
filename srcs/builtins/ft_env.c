/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:53:22 by azari             #+#    #+#             */
/*   Updated: 2023/06/04 15:24:14 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

void	ft_env(t_env *virt)
{
	
	if (!virt)
		return ;
	while (virt)
	{
		if (virt->def)
			printf("%s=%s\n", virt->var, virt->val);
		virt = virt->next;
	}
}
