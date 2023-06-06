/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:32:18 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 19:11:24 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lens;

	i = 0;
	if (s)
	{
		lens = ft_strlen(s);
		if (len > lens)
			len = lens;
		sub = (char *)malloc((len + 1) * sizeof(char));
		if (!sub)
			return (0);
		while (i < len && s[start] && start <= lens)
			sub[i++] = s[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}

char	*ft_stdup( const char *source)
{
	char	*ptr;
	int		len ;
	int		i;

	i = 0;
	if (!source)
		return (NULL);
	while (source[i] != '\0')
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	len = i ;
	if (ptr == NULL)
		return (NULL);
	while (i)
	{
		*ptr++ = *source++;
		i--;
	}
	*ptr = '\0';
	return (ptr - len);
}

static int	count_digits(long c)
{
	int	i;

	i = 0;
	if (c < 0)
		i++;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_iitoa(int n)
{
	int		i;
	int		cnt;
	char	*nbr;
	long	x;

	i = 0;
	x = n;
	cnt = count_digits(n);
	nbr = (char *)malloc((cnt + 1) * sizeof(char));
	if (!nbr)
		return (0);
	if (x < 0)
	{
		nbr[0] = '-';
		i = 1;
		x *= (-1);
	}
	nbr[cnt] = '\0';
	while (cnt > i)
	{
		cnt--;
		nbr[cnt] = (x % 10) + 48;
		x /= 10;
	}
	return (nbr);
}
