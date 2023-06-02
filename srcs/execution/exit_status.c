/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:15:58 by mechane           #+#    #+#             */
/*   Updated: 2023/06/02 11:51:37 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	set_status(int status)
{
	g_st = status;
}

int	get_status(void)
{
	if (WIFEXITED(g_st))
		return (g_st = WEXITSTATUS(g_st));
	return (1);
}
