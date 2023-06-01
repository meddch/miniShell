/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:40:04 by mechane           #+#    #+#             */
/*   Updated: 2023/06/01 17:50:01 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishel.h"

int	heredoc(char *delim)
{
	int		fd[2];
	int		len;
	char	*buff;

	if (pipe(fd) == -1 || !delim)
		return (-1);
	len = ft_strlen(delim);
	while (1)
	{
		buff = readline("> ");
		if (!buff || !ft_strncmp(delim, buff, len + 1))
			break ;
		write(fd[1], buff, ft_strlen(buff));
		write(fd[1], "\n", 1);
	}
	close(fd[1]);
	return (fd[0]);
}

bool	fill_redir(t_redir *redir, t_flag redir_type, t_token *filenode)
{
	if (redir_type == RIN && filenode->type != WORD)
		return (false);
	redir->fd_in = STDIN_FILENO;
	redir->flags = O_RDONLY;
	redir->redir_type = redir_type;
	redir->file = filenode;
	if ((redir_type & (ROUT | APPEND)))
	{
		redir->fd_in = STDOUT_FILENO;
		if (redir_type == ROUT)
			redir->flags = O_CREAT | O_WRONLY | O_TRUNC;
		else
			redir->flags = O_CREAT | O_WRONLY | O_APPEND;
	}
	else if (redir_type == HEREDOC)
		redir->fd_in = heredoc(filenode->data);
	return (true);

	
}

t_tree	*parse_redir(t_tree *cmdtree, t_token **token)
{
	t_tree	*tree;
	t_flag	redir_typ;

	if (!(*token))
		return (NULL);
	tree = cmdtree;
	while (((*token)->type) & REDIR)
	{
		redir_typ = (*token)->type;
		*token = (*token)->next;
		if ((*token)->type != WORD)
			return (NULL);
		tree = new_redir(tree);
		if (!fill_redir((t_redir *)tree , redir_typ, *token))
			return (NULL);
		(*token)= (*token)->next;
	}
	return (tree);
}