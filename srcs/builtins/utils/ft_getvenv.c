/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:28:09 by azari             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/02 15:26:39 by azari            ###   ########.fr       */
=======
/*   Updated: 2023/06/03 13:12:57 by mechane          ###   ########.fr       */
>>>>>>> 18de7abb25f41569a6fe0cdc2eb8f9ada8b7b616
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

char	*get_var(char *line)
{
	char	*var;
	size_t	i;

	i = 0;
	while (line[i] && line[i + 1] != '=')
		i++;
	if (line[i] == '+')
		var = ft_sub(line, 0, i);
	else
		var = ft_sub(line, 0, i + 1);
	return (var);
}

char	*get_val(char *line)
{
	char	*val;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	(line[i] == '=') && (i += 1);
	val = ft_sub(line, i, ft_strlen(line + i));
	return (val);
}

t_env	*ft_getvenv(char **env)
{
    t_env	*virt;
	int		i;
	virt = NULL;
	i = -1;
	while (env[++i])
		ft_envadd_back(&virt, ft_env_new(get_var(env[i]), get_val(env[i])));
	return (virt);
}
