/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:07:45 by mechane           #+#    #+#             */
/*   Updated: 2023/05/31 18:45:56 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

#include "../include/minishel.h"
# include <dirent.h>

t_token	*expand_node(t_env	*env, char	*to_expand, int	dq_flag);
t_token	*expand_sub(t_env *env, char *to_expand, int dq_flag);
t_token	*expanand_wc(char *pattern);
char	*get_env_variable(t_env *env, char *var);
char	*expand_var(char **var, t_env *env);
char	*get_non_var(char **to_check);
char	*get_valid_var(char **to_check);
char	*expansion(t_env *env, char	*to_expand);
#endif