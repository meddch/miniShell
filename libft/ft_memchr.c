/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:23:45 by mechane           #+#    #+#             */
/*   Updated: 2022/10/25 09:37:46 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		*str1;
	unsigned char		ch;

	ch = (unsigned char)c;
	str1 = (unsigned char *)str;
	while (n-- > 0)
	{
		if (*str1 == ch)
			return (str1);
		str1++;
	}
	return (NULL);
}
