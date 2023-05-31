/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:28:09 by azari             #+#    #+#             */
/*   Updated: 2023/05/31 19:07:51 by azari            ###   ########.fr       */
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
	var = ft_sub(line, 0, i + 1);
	return (var);
}

char	*get_val(char	*line)
{
	char	*val;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	(line[i] == '=') && (i += 1);
	val = ft_sub(line, i, ft__strlen(line + i));
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
