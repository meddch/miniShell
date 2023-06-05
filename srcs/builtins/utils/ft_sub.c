/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:32:18 by azari             #+#    #+#             */
/*   Updated: 2023/06/05 13:26:34 by azari            ###   ########.fr       */
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
		lens = ft_strlen(s);
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

char	*ft_stdup( const char *source)
{
	char	*ptr;
	int		len ;
	int		i;

	i = 0;
	if (!source)
		return (ft_stdup(""));
	while (source[i] != '\0')
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	len = i ;
	if (ptr == NULL)
		return (NULL);
	while (i)
	{
		*ptr++ = *source++;
		i--;
	}
	*ptr = '\0';
	return (ptr - len);
}