/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:55:42 by azari             #+#    #+#             */
/*   Updated: 2023/06/07 14:42:23 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/builtins.h"

int	ft_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

char	*ft_join(const char *s1, const char *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	if (!s1)
	{
		newstr = ft_stdup(s2);
		return (newstr);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	while (*s1)
		*newstr++ = *s1++;
	if (!s2)
		return (newstr);
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (newstr - s1_len - s2_len);
}
