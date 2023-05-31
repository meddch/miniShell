/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:54:55 by mechane           #+#    #+#             */
/*   Updated: 2023/05/31 12:33:01 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishel.h"

int	main(int ac ,char **av, char **env)
{	
	
	t_tree	*tree;
	t_env	*my_env;
	
	(void)av;
	if (ac != 1)
		return (1);
	while (true)
	{
		tree = parser(lexer());
		if (!tree)
			break ;
		exec(tree, my_env);
		gc(0, 1);
	}
	exit(g_st);
}
