/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:07:19 by mechane           #+#    #+#             */
/*   Updated: 2022/10/25 09:38:35 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*pb;
	unsigned char	car;

	pb = b;
	car = (unsigned char)c;
	while (len--)
	{
		*pb++ = car;
	}
	return (b);
}
