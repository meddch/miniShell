/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:37:24 by azari             #+#    #+#             */
/*   Updated: 2023/06/05 16:01:46 by mechane          ###   ########.fr       */
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
void ft_putstr(char *str)
{
	write(1, str, ft__strlen(str));
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
		newstr = ft_strdup(s2);
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