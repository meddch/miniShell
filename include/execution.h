/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:53:09 by mechane           #+#    #+#             */
/*   Updated: 2023/06/02 12:53:52 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define READ_END	0
# define WRITE_END	1
# define LEFT_NODE	2
# define RIGHT_NODE	3

#include "parser.h"
#include <errno.h>
// #include <sys/wait.h>


void	exec(t_tree *tree, t_env *env);
void	exit_status(int status);
void	exec_subsh(t_tree *tree, t_env *env);
void	exec_oper(t_tree *tree, t_env *env);
void	exec_pipe(t_tree *tree, t_env *env);
void	exec_cmd(t_cmd *tree, t_env *env);
// bool	is_builtin(char *cmd, char **argv);
char	*get_cmd_path(char *arg, t_env *env);
void	apply_exp(t_token **token, t_env *env);
void 	apply_wc(t_token **token);
void	exec_redir(t_tree *tree, t_env *env);
void	ft_dup2(int dst, int src);
pid_t	ft_fork(void);
int     ft_pipe(int fildes[2]);
void	set_status(int status);
int     get_status(void);
void	check_status(void);
#endif