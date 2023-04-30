/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:55:15 by mechane           #+#    #+#             */
/*   Updated: 2023/04/30 14:41:07 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
#define MINISHEL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdbool.h>

typedef struct s_token{
	int		type;
	char*	s;
	struct s_token *next;
}t_token;



struct pipecmd {
  int type;          
  struct cmd *left;  
  struct cmd *right; 
};

char	*ft_strchr(const char *str, int c);
char	*ft_strdup( const char *source );
char	*ft_strndup(char *start, char *end);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s11, char *s22);
char	*ft_strtrim(char const *s1);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif