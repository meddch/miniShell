/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:15:58 by mechane           #+#    #+#             */
/*   Updated: 2023/06/05 19:46:41 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	set_status(int status)
{
	g_st = status;
}

void	check_status(int status)
{
	if (WIFEXITED(status))
		(g_st = WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		g_st = 128 + WTERMSIG(status);
}
