/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:57:22 by mechane           #+#    #+#             */
/*   Updated: 2023/05/14 17:23:49 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../../include/minishel.h"

t_token	*lexer(void)
{
	char *prompt = "(miniShell) $ ";
	char *lineptr;
    t_token *token;
		
	while (1)
	{
		lineptr = readline(prompt);
		if (!lineptr || !ft_strcmp(lineptr, "exit"))
    		return(free(lineptr), NULL);
		if (*lineptr)
		{
			add_history(lineptr);
			token = tokenizer(lineptr);
		}
		free(lineptr);
		while(token)
		{
			printf("token :/%s/  type : %d  xpand :%d  h_doc :%d\n", token->data,token->type,token->xpand, token->h_doc);
			if (token->sub)
				printf("           sub : /%s/ type : %d xpand :%d h_doc :%d\n", token->sub->data, token->sub->type, token->sub->xpand, token->sub->h_doc);
			token = token->next;
		}
		gc(0, 1);
	}
}
