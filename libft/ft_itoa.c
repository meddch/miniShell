/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:19:45 by mechane           #+#    #+#             */
/*   Updated: 2023/05/05 12:00:23 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_count(int n)
{
	int				l;
	unsigned int	nb;

	nb = n;
	l = 0;
	if (n < 0)
	{
		l++;
		nb = -n;
	}
	while (nb >= 10)
	{
			nb /= 10;
			l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char				*res;
	int					i;
	unsigned int		nb;

	i = 0;
	nb = n;
	i = len_count(n) + 1;
	if (n == 0)
		return (ft_strdup("0"));
	res = ft_malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[i--] = '\0';
	if (n < 0)
	{
		res[0] = 45;
		nb = -n ;
	}
	while (nb > 0)
	{
		res[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (res);
}
