/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:55:15 by mechane           #+#    #+#             */
/*   Updated: 2023/05/01 15:07:54 by mechane          ###   ########.fr       */
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

#define whitespace " \t\r\n\v"
#define symbols "|()&<>"
typedef enum s_flag
{
	WORD = 97,
	DQ = 34,
	SQ = 39,
	PIPE = 124,
	RIN = 60,
	ROUT = 62,
	OPAR = 40,
	CPAR = 41,
	SPACE = 32,
	AND = 64,
	OR = 33,
	HEREDOC = 45,
	APPEND = 43,
	END = 0,
}	t_flag;

typedef struct s_token{
	t_flag			type;
	char*			s;
	struct s_token 	*next;
}t_token;

typedef struct s_pipecmd {
  int type;
  t_token *left;
  t_token *right;
}t_pipecmd;




struct pipecmd {
  int type;          
  struct cmd *left;  
  struct cmd *right; 
};

char	*ft_strchr(const char *str, int c);
char	*ft_strdup( const char *source );
char	*ft_strndup(char *start, char *end);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s11, char *s22);
char	*ft_strtrim(char const *s1);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, int start, int len);
#endif