/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wlc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:55:26 by mechane           #+#    #+#             */
/*   Updated: 2023/06/01 15:11:18 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishel.h"


bool match(char *pattern, char *string)
{
    if (*pattern == '\0')
		return (*string == '\0');
    if (*pattern == '*')
	{
        while (*string != '\0')
		{
            if (match(pattern + 1, string))
				return (true);
            string++;
        }
        return (match(pattern + 1, string));
    }
    if (*pattern == '?')
	{
        if (*string == '\0')
			return (false);
        return (match(pattern + 1, string + 1));
    }
    if (*pattern == *string) 
	{
        if (*string == '\0')
            return (true);
        return (match(pattern + 1, string + 1));
    }
    return (false);
}



t_token	*expanand_wc(char *pattern)
{
	DIR				*dirc;
	struct dirent	*item;
	t_token			*token;

	token = NULL;
	dirc = opendir(".");
	item = readdir(dirc);
	while (item)
	{
		if (match(pattern, item->d_name))
			add_back_tok(&token, new_tok(WORD, 0, 0, ft_strdup(item->d_name)));
		item = readdir(dirc);
	}
	closedir(dirc);
	if (!token)
		add_back_tok(&token, new_tok(WORD, 0, 0, pattern));
	return (token);
}
