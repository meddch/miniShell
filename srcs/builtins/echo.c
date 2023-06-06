/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:16:35 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 20:06:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

int	ft_catch_flag(char **args, int i)
{
	int	j;

	while (args[i])
	{
		j = 0;
		if (args[i][j] != '-')
			return (i);
		else if (args[i][j] == '-' && !args[i][j + 1])
			return (i);
		else if (args[i][j] == '-')
			while (args[i][++j])
				if (args[i][j] != 'n')
					return (i);
		i++;
	}
	return (i);
}

void	echo(char **args)
{
	int	i;
	int	flag;

	set_status(0);
	if (!args[1])
		return ((void)write(1, "\n", 1));
	i = 1;
	flag = i;
	if (args[i][0] == '-' && args[i][1] == 'n')
		i = ft_catch_flag(args, i);
	(flag == i) && (flag = 0);
	while (args[i])
	{
		ft_putstr(args[i]);
		(args[i + 1]) && (write(1, " ", 1));
		i++;
	}
	(!flag) && (write(1, "\n", 1), i = 1337);
}
