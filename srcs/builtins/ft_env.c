/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:53:22 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 20:06:34 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	ft_env(t_env *virt)
{
	t_env	*path;

	set_status(0);
	if (!virt)
		return ;
	path = ft_srchenv(virt, "PATH");
	if (!path)
		return (set_status(127), ft_printf_fd(2, "env: No such file or \
directory\n"));
	while (virt)
	{
		if (virt->val != NULL)
			printf("%s=%s\n", virt->var, virt->val);
		virt = virt->next;
	}
}
