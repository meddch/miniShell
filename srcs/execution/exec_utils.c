/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:33:04 by mechane           #+#    #+#             */
/*   Updated: 2023/05/28 17:33:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"


void	exit_status(int status)
{
	if (WIFEXITED(status))
		g_st = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_st = 128 + WTERMSIG(status);
}