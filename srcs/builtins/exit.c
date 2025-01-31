/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:52 by azari             #+#    #+#             */
/*   Updated: 2023/06/08 16:44:13 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	ft_code_exit(int e_code)
{
	exit(e_code);
}

void	ft_exit(char **args)
{
	if (!args[1])
		return (write(2, "exit\n", 5), ft_code_exit(0));
	if (!ft_digit(args[1]) || ft_strlen(args[1]) > 19)
		return (ft_printf_fd(2, "exit: %s: numeric argument required\n",
				args[1]), ft_code_exit(255));
	else if (args[2])
		return (set_status(1), ft_printf_fd(2, "exit\nexit: too many \
arguments\n"));
	else
	{
		write(1, "exit\n", 6);
		ft_code_exit(ft_atoi(args[1]));
	}
}
