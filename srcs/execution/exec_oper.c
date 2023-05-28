/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:58:51 by mechane           #+#    #+#             */
/*   Updated: 2023/05/28 13:20:41 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"

void	exec_oper(t_tree *tree, t_env *env)
{
	exec(((t_connector *)tree)->left, env);
	if (tree->node_type == NODE_AND && !g_st)
		exec(((t_connector *)tree)->right, env);
	if (tree->node_type == NODE_OR && g_st)
		exec(((t_connector *)tree)->right, env);
}