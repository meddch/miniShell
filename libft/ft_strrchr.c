/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:24:50 by mechane           #+#    #+#             */
/*   Updated: 2022/10/19 12:46:49 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*chr;
	char	cc;

	cc = (char)c;
	len = ft_strlen(str);
	chr = (char *)str;
	while (len >= 0)
	{
		if (chr[len] == cc)
			return (chr + len);
		len--;
	}
	return (NULL);
}
