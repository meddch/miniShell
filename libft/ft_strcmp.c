/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:54:51 by mechane           #+#    #+#             */
/*   Updated: 2023/06/06 16:42:29 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s11, char *s22)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (!s11 || !s22)
		return (1);
	s2 = (unsigned char *)s22;
	s1 = (unsigned char *)s11;
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
