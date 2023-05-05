/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:16:43 by mechane           #+#    #+#             */
/*   Updated: 2023/05/05 12:01:40 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sbr;
	unsigned int	i;
	unsigned int	j;

	j = len;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		j = ft_strlen(s + start);
	sbr = ft_malloc((j + 1) * sizeof(char));
	if (sbr == NULL)
		return (NULL);
	i = j;
	while (j--)
	{
		*sbr = s[start];
		start++;
		sbr++;
	}
	*sbr = '\0';
	return (sbr - i);
}
