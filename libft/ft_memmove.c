/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:02:31 by mechane           #+#    #+#             */
/*   Updated: 2022/10/22 12:06:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (s == NULL && d == NULL)
		return (NULL);
	if (d > s)
	{
		while (i < n)
		{
			i++;
			d[n - i] = s[n - i];
		}
		return (dst);
	}
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
