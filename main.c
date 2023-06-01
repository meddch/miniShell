/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:54:55 by mechane           #+#    #+#             */
/*   Updated: 2023/06/01 13:59:35 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishel.h"

void displayTree(t_tree *root, int level)
{
    if (root == NULL)
        return;
    if (root->node_type == NODE_PIPE || root->node_type == NODE_AND || root->node_type == NODE_OR)
        displayTree(((t_connector *)root)->left, level + 1);

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
        displayTree(((t_connector *)root)->right, level + 1);
    }
}



int	main(int ac ,char **av, char **env)
{	
	
	// t_tree	*tree;
	// t_token	*token;
	// char *prompt = "(minishell) $ ";
	// char *lineptr;
	(void)ac;
	(void)av;
	t_env	*my_env;
    char *args[20] = {"echo", "-nnnnn-nnnnn", "speedup", NULL};
	my_env = ft_getvenv(env);
    echo(args);
	// int len = ft_envsize(my_env);
	// ft_printf_fd(1, "--[%d]--\n", len);
	// ft_env(my_env);
	// if (ac != 1)
	// 	return (1);
	// while (1)
	// {
	// 	lineptr = readline(prompt);
	// 	if (!lineptr)
    // 		break ;
	// 	if (*lineptr)
	// 	{
	// 		add_history(lineptr);
	// 		token = tokenizer(lineptr);
	// 	}
	// 	free(lineptr);
	// 	tree = parser(&token);
	// 	if (!tree)
	// 		break ;
	// 	// displayTree(tree,0);
	// 	// exec(tree, my_env);
	// 	gc(0, 1);
	// }
	// exit(g_st);
}


