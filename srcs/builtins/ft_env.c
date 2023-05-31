/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:53:22 by azari             #+#    #+#             */
/*   Updated: 2023/05/31 18:53:49 by azari            ###   ########.fr       */
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
			ft_printf_fd(1, "%s=%s\n", virt->var, virt->val);
		virt = virt->next;
	}
}
