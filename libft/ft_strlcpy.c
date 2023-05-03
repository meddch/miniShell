/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:48:02 by mechane           #+#    #+#             */
/*   Updated: 2022/10/13 20:45:58 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	i = 0;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src1[i] != '\0' && (dstsize - 1) > i)
	{
		dst1[i] = src[i];
		i++;
	}
	dst1[i] = '\0';
	return (ft_strlen(src));
}
