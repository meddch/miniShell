/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:55:04 by mechane           #+#    #+#             */
/*   Updated: 2022/10/29 10:35:13 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	strlen_nw(const char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_read(char *stash, int fd, char *buff)
{
	char	*temp;
	int		ret;

	temp = NULL;
	ret = 1 ;
	while (ret > 0 && !ft_strchr(buff, '\n'))
	{	
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		temp = ft_strjoin(stash, buff);
		free(stash);
		stash = temp;
	}
	free (buff);
	return (stash);
}

char	*get_stash(char *stash, int fd)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(stash);
		return (NULL);
	}
	buff[0] = 0;
	stash = ft_read(stash, fd, buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_stash(stash, fd);
	if (!stash)
		return (NULL);
	if (!*stash)
	{	
		free(stash);
		return (stash = 0);
	}
	line = ft_substr(stash, 0, strlen_nw(stash) + 1);
	temp = ft_substr(stash, strlen_nw(stash) + 1,
			ft_strlen(stash + strlen_nw(stash) +1));
	free(stash);
	stash = temp ;
	return (line);
}
