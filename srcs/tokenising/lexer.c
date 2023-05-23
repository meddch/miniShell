/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:57:22 by mechane           #+#    #+#             */
/*   Updated: 2023/05/23 11:51:25 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../../include/minishel.h"


void displayTree(t_tree *root, int level)
{
    if (root == NULL)
        return;
    if (root->node_type == NODE_PIPE || root->node_type == NODE_AND || root->node_type == NODE_OR)
        displayTree(((t_connector *)root)->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("\t");

    switch (root->node_type)
    {
        case NODE_AND:
            printf("AND Node\n");
            break;
        case NODE_OR:
            printf("OR Node\n");
            break;
        case NODE_PIPE:
            printf("PIPE Node\n");
            break;
        case NODE_SUBSH:
            printf("SUBSHELL Node\n");
            break;
        case NODE_REDIR:
            printf("REDIR Node ---> file : %s\n",((t_redir *)root)->file->data);
            break;
        case NODE_CMD:
            printf("CMD Node ---> data : %s\n",((t_cmd*)root)->list->data);
            break;
        default:
            printf("Unknown Node\n");
            break;
    }

    if (root->node_type == NODE_SUBSH)
    {
        displayTree(((t_subsh *)root)->subsh, level + 1);
    }
    else if (root->node_type == NODE_REDIR)
    {
        displayTree(((t_redir *)root)->cmdtree, level + 1);
    }
    else if (root->node_type != NODE_CMD)
    {
        displayTree(((t_connector *)root)->left, level + 1);
    }
}

void print_token(t_token *token)
{
    if (!token)
        return;
    while(token)
    {
        printf(" token type %d\n      token data : %s\n",token->type, token->data);
        token = token->next;
    }
}

t_token	*lexer(void)
{
	char *prompt = "(miniShell) $ ";
	char *lineptr;
    t_token *token;
	t_tree	*tree;
		
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
		print_token(token);
        tree = parser(&token);
		displayTree(tree, 0);
	}
	return (token);
}
