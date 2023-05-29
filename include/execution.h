/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:53:09 by mechane           #+#    #+#             */
/*   Updated: 2023/05/29 15:01:21 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define READ_END	0
# define WRITE_END	1
# define LEFT_NODE	2
# define RIGHT_NODE	3

#include "parser.h"

void	exec(t_tree *tree, t_env *env);
void	exit_status(int status);
void	exec_subsh(t_tree *tree, t_env *env);
void	exec_oper(t_tree *tree, t_env *env);
void	exec_pipe(t_tree *tree, t_env *env);
void	exec_cmd(t_cmd *tree, t_env *env);
bool	is_builtin(char *cmd, char **argv);
char	*get_cmd_path(char *arg, t_env *env);
#endif