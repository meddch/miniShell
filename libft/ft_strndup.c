/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:54:00 by mechane           #+#    #+#             */
/*   Updated: 2023/05/05 09:37:44 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *start, char *end)
{
	char	*ptr;
	int		len ;
	int i;

	if (!start)
		return (NULL);
	len = i = ft_strlen(start) - ft_strlen(end);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i)
	{
		*ptr++ = *start++;
		i--;
	}
	*ptr = '\0';
	ptr -= len;
	return (ptr);
}