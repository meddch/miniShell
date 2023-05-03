/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:38:10 by mechane           #+#    #+#             */
/*   Updated: 2022/10/22 12:25:10 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	hay = (char *)haystack;
	if (!hay && (len == 0))
		return (NULL);
	if ((!*haystack && !*needle) || !*needle)
		return (hay);
	j = 0;
	while (j < len && len != 0 && *hay)
	{
		if (*hay == *needle)
		{
			i = 1;
			while (needle[i] == hay[i] && needle[i] && j + i < len)
				i++;
			if (!needle[i])
				return ((hay));
		}
		hay++;
		j++;
	}
	return (NULL);
}
