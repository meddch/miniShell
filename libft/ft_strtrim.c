/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:09:29 by mechane           #+#    #+#             */
/*   Updated: 2022/10/16 10:22:29 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trm;
	unsigned int	l;
	int				i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[i]))
		i++;
	l = ft_strlen(s1);
	while (ft_strchr(set, s1[l]) && (l > 0))
		l--;
	trm = ft_substr(s1, i, (l - i) + 1);
	return (trm);
}
