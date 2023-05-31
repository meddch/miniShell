/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:51:39 by mechane           #+#    #+#             */
/*   Updated: 2023/05/31 20:34:24 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_sstrlen(const char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}	

char	*ft_sstrjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	if (!s1)
	{
		newstr = ft_sstrdup(s2);
		return (newstr);
	}
	s1_len = ft_sstrlen(s1);
	s2_len = ft_sstrlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
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

char	*ft_sstrchr(const char *str, int c)
{
	char	*s;
	char	ch;

	if (!str)
		return (NULL);
	ch = (char)c;
	s = (char *)str;
	while (*s != ch)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return (s);
}

char	*ft_sstrdup(const char *source)
{
	char	*ptr;
	int		len ;
	int		i;

	i = 0;
	i = ft_sstrlen(source);
	ptr = (char *)malloc((i + 1) * sizeof(char));
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

char	*ft_ssubstr(char const *s, unsigned int start, size_t len)
{
	char			*sbr;
	unsigned int	i;
	unsigned int	j;

	j = len;
	if (!s)
		return (NULL);
	if (start >= ft_sstrlen(s))
		return (ft_sstrdup(""));
	if (ft_sstrlen(s + start) < len)
		j = ft_sstrlen(s + start);
	sbr = (char *)malloc((j + 1) * sizeof(char));
	if (sbr == NULL)
		return (NULL);
	i = j;
	while (j--)
	{
		*sbr = s[start];
		start++;
		sbr++;
	}
	*sbr = '\0';
	return (sbr - i);
}
