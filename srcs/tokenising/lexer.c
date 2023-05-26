/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:57:22 by mechane           #+#    #+#             */
/*   Updated: 2023/05/26 15:47:38 by mechane          ###   ########.fr       */
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
        printf(" token type %d\n   token data : %s\n",token->type, token->data);
        token = token->next;
    }
}

int	check_token(t_lex *lex, char **line)
{
	char *cmd;
	
	cmd = *line;
	check_symbols(lex, &cmd);
	if ((lex->sq && *(cmd + 1)!= '\'') || (lex->dq && *(cmd + 1) != '\"'))
	{
		cmd++;
		check_quotes(lex, &cmd);
	}
	else if (((lex->sq && *(cmd + 1) == '\'') || (lex->dq && *(cmd + 1) == '\"')) && lex->spc)
	{
		cmd++;
		if ( *(cmd + 1) && ft_strchr(WHITESPACE, *(cmd + 1)))
			add_back_tok(&lex->token, new_tok(WORD, false, false, ft_strdup("")));
		if (*cmd == '\"')
			(lex->dq = !lex->dq); 
		if (*cmd == '\'')
			(lex->sq = !lex->sq);
	}
	cmd++;
	*line = cmd;
	return (0);
}

int check_w_token(t_lex *lex, char	**line)
{
	char *cmd;
	
	cmd = *line;
	if (lex->spc)
	{
		add_back_tok(&lex->token, new_tok(WORD, true, true, 
				get_word(&cmd)));
		lex->spc = false;
	}
	else if (!lex->spc)
	{
		lex->tmp = last_tok(lex->token);
		while (lex->tmp->sub)
			lex->tmp = lex->tmp->sub;
		lex->tmp->sub = new_tok(WORD, true, true, 
				get_word(&cmd));
	}
	*line = cmd;
	return(0);
}

t_token	*lexer(void)
{
	char *prompt = "(minishell) $ ";
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
