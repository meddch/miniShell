/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:40:04 by mechane           #+#    #+#             */
/*   Updated: 2023/05/22 17:13:42 by mechane          ###   ########.fr       */
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