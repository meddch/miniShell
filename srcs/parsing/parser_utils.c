/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:40:04 by mechane           #+#    #+#             */
/*   Updated: 2023/06/04 19:58:10 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishel.h"

void	signal_herdoc(int sig)
{
	(void)sig;
	close(STDIN_FILENO);
}
void	open_stdin(int fd[2])
{
	int	fd_p;

	fd_p = open(ttyname(STDERR_FILENO), O_RDONLY);
	if (fd_p == -1)
	{
		write(2, "can't open stdin", 17);
	}
	close(fd[0]);
	close(fd[1]);
}

int	heredoc(char *delim)
{
	int		fd[2];
	int		len;
	char	*buff;

	if (ft_pipe(fd) == -1 || !delim)
		return (-1);
	len = ft_strlen(delim);
	signal(SIGINT, signal_herdoc);
	while (isatty(STDIN_FILENO))
	{
		buff = readline("> ");
		if (!buff || !ft_strncmp(delim, buff, len + 1))
			break ;
		write(fd[1], buff, ft_strlen(buff));
		write(fd[1], "\n", 1);
	}
	signal(SIGINT, inter_handler);
	if (!isatty(STDIN_FILENO))
		return (open_stdin(fd), set_status(1), -1);
	close(fd[1]);
	return (fd[0]);
}

bool	fill_redir(t_redir *redir, t_flag redir_type, t_token **filenode)
{
	t_token *hold;

	hold = *filenode;
	if (redir_type == RIN && hold->type != WORD)
		return (false);
	redir->fd_in = STDIN_FILENO;
	redir->flags = O_RDONLY;
	redir->redir_type = redir_type;
	redir->file = copy_token(&hold);
	if ((redir_type & (ROUT | APPEND)))
	{
		redir->fd_in = STDOUT_FILENO;
		if (redir_type == ROUT)
			redir->flags = O_CREAT | O_WRONLY | O_TRUNC;
		else
			redir->flags = O_CREAT | O_WRONLY | O_APPEND;
	}
	else if (redir_type == HEREDOC)
		redir->fd_in = heredoc(join_delim(*filenode));
	if (redir_type == HEREDOC && redir->fd_in == -1)
		return ((*filenode)->type = SIGIGNOR , NULL);
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
		if (!fill_redir((t_redir *)tree , redir_typ, token))
			return (NULL);
		(*token)= (*token)->next;
	}
	return (tree);
}