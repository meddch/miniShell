/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:25:47 by azari             #+#    #+#             */
/*   Updated: 2023/05/31 19:12:31 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

void	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	s;
	int		i;

	i = -1;
	va_start(s, str);
	while (str[++i])
	{
		(str[i] != '%') && (i += 0, write(fd, &str[i], 1));
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == 's')
				ft_putstr__fd(va_arg(s, char *), fd);
			else if (str[i + 1] == 'd')
				ft_putnbr__fd(va_arg(s, int), fd);
			else
				write(fd, &str[i + 1], 1);
			i++;
		}
	}
}
