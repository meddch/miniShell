/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:32:18 by azari             #+#    #+#             */
/*   Updated: 2023/06/03 14:25:19 by azari            ###   ########.fr       */
=======
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:32:18 by azari             #+#    #+#             */
/*   Updated: 2023/06/03 13:13:17 by mechane          ###   ########.fr       */
>>>>>>> 18de7abb25f41569a6fe0cdc2eb8f9ada8b7b616
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
<<<<<<< HEAD
		lens = ft__strlen(s);
=======
		lens = ft_strlen(s);
>>>>>>> 18de7abb25f41569a6fe0cdc2eb8f9ada8b7b616
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
