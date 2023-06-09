/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:48:38 by mechane           #+#    #+#             */
/*   Updated: 2023/06/09 15:25:58 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../include/minishel.h"

# define NODE_AND	0
# define NODE_OR	1	
# define NODE_PIPE	2	
# define NODE_SUBSH	3	
# define NODE_REDIR	4	
# define NODE_CMD	5

typedef struct s_tree
{
	int	node_type;
}				t_tree;

typedef struct s_connector
{
	int		node_type;
	t_tree	*left;
	t_tree	*right;
}				t_connector;

typedef struct s_subsh
{
	t_flag	node_type;
	t_tree	*subsh;
}				t_subsh;

typedef struct s_redir
{
	int			node_type;
	t_flag		redir_type;
	int			flags;
	int			fd_in;
	int			fd_out;
	t_token		*file;
	t_tree		*cmdtree;
}				t_redir;

typedef struct s_cmd
{
	int		node_type;
	t_token	*list;
}				t_cmd;

t_tree	*constract_block(int type, t_tree *left, t_tree *right);
t_tree	*constract_sub(t_tree *tree);
t_tree	*constract_pipe(t_tree *left, t_tree *right);
t_tree	*new_redir(t_tree *tree);
t_token	*copy_token(t_token **tok);
t_tree	*parser(t_token **tok);
t_tree	*parse_pipeline(t_token **token);
t_tree	*parse_block(t_token **token);
t_tree	*parse_sub(t_token **token);
t_tree	*parse_cmd(t_token **token);
t_tree	*parse_redir(t_tree *cmdtree, t_token **token);
t_tree	*new_cmd(void);
void	add_token_list(t_token **list, t_token **token);
char	*join_delim(t_token *delim);

#endif