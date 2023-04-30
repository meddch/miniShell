/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:54:55 by mechane           #+#    #+#             */
/*   Updated: 2023/04/30 15:36:54 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

char whitespace[] = " ";
char symbols[] = "|()&<>";

int check_quoting(char *s)
{
	int flag;
	int count;
	
	count = 0;
	flag = 0;
	while(*s)
	{
		if (!flag && *s =='"')
			flag = 1;
		if (!flag && *s =='\'')
			flag = 2;
		if ((*s == '"' && (!flag || flag == 1)) || ((*s == '\'' && (!flag || flag == 2))))
			count++;
		s++;
	}
	if (count % 2)
		return (printf(" syntax error \n"));
	else 
		return (0);
}

int	gettoken(char **ps, char *es, char **q, char **eq)
{
  char *s;
  int ret;
  
  s = *ps;
  es = s + ft_strlen(s);
  while(s < es  && ft_strchr(whitespace, *s))
    s++;
  if(q)
    *q = s;
  	ret = *s;
	if (!*s || *s == '\n')
		ret = 0;
	if (ft_strchr("|()&<>", *s))
	{
			s++;
		if (*s == '>')
		{
			ret = '+';
			s++;
		}	
	}
	else
    {
		ret = 'a';
    	while(s < es  && !ft_strchr(whitespace, *s) && !ft_strchr(symbols, *s))
      		s++;
	}
  if(eq)
    *eq = s;
  while(s < es && *s != '\n' && ft_strchr(whitespace, *s))
    s++;
  *ps = s;
  return ret;  
}

t_token	*ft_new(int type, char *s)
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

int	main(int ac ,char **av, char **env)
{	
	char *prompt = "(miniShell) $ ";
	char *lineptr;
	char *q;
	char *es;
	char *eq;
	char *tok;
	int ret;
	
	(void)ac; (void)av;
    t_token *token = NULL;
	while (1)
	{
		lineptr = readline(prompt);
		if (!lineptr || !ft_strcmp(lineptr, "exit"))
    		return(free(lineptr), 0);
		while((ret = (gettoken(&lineptr, es,&q,&eq))) != 0)
		{
			tok = ft_strndup(q,eq);
			check_quoting(tok);
			tok = ft_strtrim(tok);
			add_back(&token,ft_new(ret, tok));
			// printf("%s\n",tok);
		}
	while(token)
	{
		// printf("type : %d\n",token->type);
		printf("token : : %s\n",token->s);
		token = token->next;
	}

    }
}



