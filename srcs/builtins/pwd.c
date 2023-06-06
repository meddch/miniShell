/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:52:20 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 20:01:36 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	ft_putstrr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	pwd(t_env *env)
{
	set_status(1);
	if (ft_srchenv(env, PWD))
		return (set_status(0), ft_putstrr(ft_srchenv(env, PWD)->val));
}
