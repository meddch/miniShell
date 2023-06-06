/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:30:25 by mechane           #+#    #+#             */
/*   Updated: 2023/06/06 13:44:54 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	inter_handler(int sig)
{
		(void)sig;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		set_status(1);
}
void sig_hand(int sig)
{
	if (sig == SIGINT)
		write(1,"",1);
	if (sig == SIGQUIT)
		write(1,"Quit: 3",7);
	exit(120 + sig);
}
void sig_ch(pid_t pid)
{
	if (pid == 0)
	{
		signal(SIGINT, sig_hand);
		signal(SIGQUIT, sig_hand);
	}
	else
		signal(SIGINT, SIG_IGN);
}