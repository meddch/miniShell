/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:52 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 20:06:28 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	ft_code_exit(int e_code)
{
	rl_clear_history();
	exit(e_code);
}

void	ft_exit(char **args)
{
	if (!args[1])
		return (write(2, "exit\n", 5), ft_code_exit(0));
	if (!ft_digit(args[1]))
		return (ft_printf_fd(2, "exit: %s: numeric argument required",
				args[1]), ft_code_exit(255));
	else if (args[2])
		return (set_status(1), ft_printf_fd(2, "exit\nexit: too many \
arguments\n"));
	else
		ft_code_exit(ft_atoi(args[2]));
}
