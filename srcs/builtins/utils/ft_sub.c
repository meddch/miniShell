/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:32:18 by azari             #+#    #+#             */
/*   Updated: 2023/06/03 14:25:19 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lens;

	i = 0;
	if (s)
	{
		lens = ft__strlen(s);
		if (len > lens)
			len = lens;
		sub = (char *)malloc((len + 1) * sizeof(char));
		if (!sub)
			return (0);
		while (i < len && s[start] && start <= lens)
			sub[i++] = s[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}
