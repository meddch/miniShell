/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:24:57 by mechane           #+#    #+#             */
/*   Updated: 2023/05/31 20:33:32 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

size_t	ft_sstrlen(const char *s);
char	*ft_sstrjoin(const char *s1, const char *s2);
char	*ft_sstrchr(const char *str, int c);
char	*ft_sstrdup(const char *source);
char	*ft_ssubstr(char const *s, unsigned int start, size_t len);
size_t	strlen_nw(const char *s);
char	*get_next_line(int fd);
char	*ft_read(char *stash, int fd, char *buff);
char	*get_stash(char *stash, int fd);
#endif