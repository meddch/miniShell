/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:52:20 by azari             #+#    #+#             */
/*   Updated: 2023/06/03 13:12:00 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"


void	ft_putstrr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	pwd(void)
{
	char	path[PATH_MAX];

	if (getcwd(path, sizeof(path)))
		ft_putstrr(path);
}
