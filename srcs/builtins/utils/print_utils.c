/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:37:24 by azari             #+#    #+#             */
/*   Updated: 2023/06/06 20:06:04 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

size_t	ft__strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
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

int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft__strlen(s));
	write(fd, "\n", 1);
	return (0);
}

void	ft_putstr(char *str)
{
	write(1, str, ft__strlen(str));
}
