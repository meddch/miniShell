/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:48:38 by mechane           #+#    #+#             */
/*   Updated: 2023/05/20 13:12:08 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "../include/minishel.h"

typedef struct s_tree
{
	int	cmd_type;
}				t_tree;

typedef struct s_connector
{
	int	cmd_type;
	t_tree *left;
	t_tree *right;
}				t_connector;

typedef struct s_subsh
{
	int	cmd_type;
	t_tree *subsh;
}				t_subsh;

typedef struct s_cmd
{
	int	cmd_type;
	t_token	*cmd;	
}				t_cmd;

typedef struct s_redir 
{
	t_flag		redir_type;
	int			flags;
	int			fd_in;
	int			fd_out;
	t_token		*file;
	t_tree	*cmdtree;
}				t_redir;

t_tree	*constract_block(int type, t_tree *left, t_tree *right);
t_tree	*constratct_sub(t_tree *tree);
t_tree	*constract_pipe(t_tree *left, t_tree *right);
t_redir	*new_redir(t_tree *tree);

#endif