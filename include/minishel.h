/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:56:44 by mechane           #+#    #+#             */
/*   Updated: 2023/06/09 15:32:33 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H

# include "builtins.h"
# include "tokenizer.h"
# include "expander.h"
# include "execution.h"
# include "parser.h"
# include "../libft/libft.h"
# include "../gc/gc.h"
# include "../gnl/get_next_line.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h> 

int	g_st;
void	inter_handler(int seg);
void	sig_hand(int sig);
void	sig_ch(pid_t pid);

#endif