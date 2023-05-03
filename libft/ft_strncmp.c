/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:02:58 by mechane           #+#    #+#             */
/*   Updated: 2022/10/22 12:07:43 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s11, const char *s22, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s2 = (unsigned char *)s22;
	s1 = (unsigned char *)s11;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
