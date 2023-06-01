/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:37:24 by azari             #+#    #+#             */
/*   Updated: 2023/05/31 19:12:16 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

size_t	ft__strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr__fd(long val, int fd)
{
	(val < 0) && (write(1, "-", 1), val *= -1);
	(val > 9) && (ft_putnbr__fd((val / 10), fd), val += 0);
	write(fd, &"0123456789"[val % 10], 1);
}

void	ft_putstr__fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft__strlen(s));
}
char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lens;

	i = 0;
	if (s)
	{
		lens = ft__strlen(s);
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