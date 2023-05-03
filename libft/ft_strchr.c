/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:24:06 by mechane           #+#    #+#             */
/*   Updated: 2022/10/24 18:59:56 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	char	ch;

	ch = (char)c;
	s = (char *)str;
	while (*s != ch)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return (s);
}
