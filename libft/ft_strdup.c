/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:03:57 by mechane           #+#    #+#             */
/*   Updated: 2023/06/07 18:20:16 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup( const char *source )
{
	char	*ptr;
	int		len ;
	int		i;

	i = 0;
	if (!source)
		return (NULL);
	while (source[i] != '\0')
		i++;
	ptr = ft_malloc((i + 1) * sizeof(char));
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
