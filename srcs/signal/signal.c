/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:30:25 by mechane           #+#    #+#             */
/*   Updated: 2023/06/04 00:44:41 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	*inter_handler(int seg)
{
	// printf("%d\n",seg);
	if (seg != SIGINT)
		return (NULL);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_status(1);
    return (NULL);
}