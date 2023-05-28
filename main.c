/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:54:55 by mechane           #+#    #+#             */
/*   Updated: 2023/05/26 15:35:31 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishel.h"

int	main(int ac ,char **av, char **env)
{	
	
	t_token *token;
	
	(void)av,(void)env;
	if (ac != 1)
		return (1);
	token = lexer();
	
	// parser(&token);
}
