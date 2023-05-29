/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:07:45 by mechane           #+#    #+#             */
/*   Updated: 2023/05/29 12:08:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

#include "../include/minishel.h"
# include <dirent.h>

typedef struct v_env
{
	char			*val;
	char			*var;
	struct v_env	*next;
	int				*def;
}			t_env;

t_token	*expand_sub(t_env *env, char *to_expand, t_token **expand, int dq_flag);
t_token	*expand_node(t_env	*env, char	*to_expand, int	dq_flag);
t_token	*expanand_wc(char *pattern);
char	*get_env_variable(t_env *env, char *var);
char	*expand_var(char **var, t_env *env);
char	*get_non_var(char **to_check);
char	*get_valid_var(char **to_check);
#endif