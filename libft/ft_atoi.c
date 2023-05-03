/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:29:33 by mechane           #+#    #+#             */
/*   Updated: 2022/10/23 23:06:05 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_long(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long		res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while (((((str[i] >= 9) && (str[i] <= 13))
				|| (str[i] == ' ')) && (str[i] != '\0')))
				i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res < (res / 10))
		return (check_long(sign));
	return ((int)(sign * res));
}
