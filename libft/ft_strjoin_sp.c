/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:39:01 by mechane           #+#    #+#             */
/*   Updated: 2023/05/29 12:40:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sp(char  *s1, char *s2, char c)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	str = ft_malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i++] = c;
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}