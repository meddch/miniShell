/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:54:55 by mechane           #+#    #+#             */
/*   Updated: 2023/06/08 16:44:07 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishel.h"

void	ft_prompt(t_env **env)
{
	t_tree	*tree;
	t_token	*token;
	char	*prompt;
	char	*lineptr;

	prompt = "(minishell)-$ ";
	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, inter_handler);
		tree = NULL;
		token = NULL;
		lineptr = readline(prompt);
		if (!lineptr)
			return (ft_printf_fd(1, "exit\n"), ft_code_exit(0));
		add_history(lineptr);
		token = tokenizer(lineptr);
		free(lineptr);
		tree = parser(&token);
		exec(tree, env);
		gc(0, 1);
	}
}

int	main(int ac, char **av, char **env)
{	
	t_env	*my_env;

	if (ac != 1)
		return (1);
	(void)av;
	rl_catch_signals = 0;
	g_st = 0;
	my_env = ft_getvenv(env);
	ft_prompt(&my_env);
	exit(g_st);
}
