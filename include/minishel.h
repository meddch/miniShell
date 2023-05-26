/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:56:44 by mechane           #+#    #+#             */
/*   Updated: 2023/05/26 15:54:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H

# include "tokenizer.h"
# include "../libft/libft.h"
# include "parser.h"
# include "../gc/gc.h"

int g_es;

typedef struct v_env
{
	char			*val;
	char			*var;
	struct v_env	*next;
	int				*def;
}t_env;

#endif