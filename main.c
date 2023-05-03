/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:54:55 by mechane           #+#    #+#             */
/*   Updated: 2023/05/03 10:30:28 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	check_quoting(char *s)
{
	int	flag;
	int	count;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (!flag && *s == '"')
			flag = 1;
		if (!flag && *s == '\'')
			flag = 2;
		if ((*s == '"' && (!flag || flag == 1)) || ((*s == '\''
					&& (!flag || flag == 2))))
			count++;
		s++;
	}
	if (count % 2)
		return (printf(" syntax error \n"));
	else
		return (0);
}
// refactor 
void	check_symbols(char **ps, int *ret, char *es)
{
	char	*s;

	s = *ps;
	if (*s == '>' && *(s + 1) == '>')
		*ret = APPEND, s+= 2;
	else if (*s == '<' && *(s + 1) == '<')
		*ret = HEREDOC, s+= 2;
	else if (*s == '|' && *(s + 1) == '|')
		*ret = OR, s+= 2;
	else if (*s == '&' && *(s + 1) == '&')
		*ret = AND,s+= 2;
	else
		s++;
	while (s < es && ft_strchr(WHITESPACE, *s))
		s++;
	*ps = s;
}
// refactor 
void	check_other(char **ps, int *ret, char *es)
{
	char	*s;

	s = *ps;
	if (ft_strchr("\"", *s))
	{
		*ret = DQ, s++;
		while(s < es && *s != '"')
			s++;
		s++;
	}
	else if (ft_strchr("'", *s))
	{
		*ret = SQ,s++;
		while (s < es && *s != '\'')
			s++;
		s++;
	}
	else if (ft_strchr(WHITESPACE, *s))
	{
		*ret = SPACE;
		while (s < es  && ft_strchr(WHITESPACE, *s))
			s++;
	}
	*ps = s;
}
// refactor 
int	gettoken(char **ps, char *es, char **q, char **eq)
{
	char	*s;
	int	ret;

  s = *ps;
  es = s + ft_strlen(s);
 	if(q)
    *q = s, ret = *s;
	if (!*s || *s == '\n')
		ret = 0;
	if (ft_strchr(SYMBOLS, *s))
		check_symbols(&s, &ret, es);
	else if (ft_strchr("\"", *s) || ft_strchr("'", *s) || ft_strchr(WHITESPACE, *s))
		check_other(&s, &ret, es);
	else
    {
		ret = WORD;
    	while(s < es  && !ft_strchr(WHITESPACE, *s) && !ft_strchr(SYMBOLS, *s))
      		s++;
	}
  if(eq)
    *eq = s;
  *ps = s;
  return ret;  
}

t_token	*ft_new(t_flag type, char *s)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->s = s;
	new->next = NULL;
	return (new);
}
void	add_back(t_token **lst, t_token *new)
{
	t_token	*count;

	if (!lst)
		return;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	count = *lst;
	while (count->next)
		count = count->next;
	count->next = new;
}

void lexer(t_token **token, char *line)
{
	char *q;
	char *es;
	char *eq;
	char *tok;
	int ret;

	es = NULL;
	while((ret = (gettoken(&line, es,&q,&eq))) != 0)
		{
			tok = ft_strndup(q,eq);
			check_quoting(tok);
			add_back(token,ft_new(ret, tok));
		}
		add_back(token,ft_new(ret, NULL));
}

int	main(int ac ,char **av, char **env)
{	
	char *prompt = "(miniShell) $ ";
	char *lineptr;
    t_token *token = NULL;
	
	
	(void)av,(void)env;
	if (ac != 1)
		return (1);
	while (1)
	{
		lineptr = readline(prompt);
		if (!lineptr || !ft_strcmp(lineptr, "exit"))
    		return(free(lineptr), 0);
		if (*lineptr)
			add_history(lineptr);
		lexer(&token, lineptr);
		while(token)
		{
			printf("token :/%s/\n",token->s);
			printf("type : %d\n",token->type);
			token = token->next;
		}
    }
}
