/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:22:32 by azari             #+#    #+#             */
/*   Updated: 2023/06/02 11:58:59 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#define HOME "~"
#define PREV_DIR "-"
#define D_X "declare -x"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
# include "../libft/libft.h"

typedef struct s_env
{
	char			*var;
	char			*val;
	int				def;
	struct s_env	*next;
}					t_env;

char	*ft_sub(char const *s, unsigned int start, size_t len);
void	ft_printf_fd(int fd, const char *str, ...);
void	ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_env_new(char *evar, char *eval);
void	ft_delnode(t_env **env, char *var);
int		ft_catch_flag(char **args, int i);
void	export(t_env **env, char **args);
void	ft_putnbr__fd(long val, int fd);
void	ft_putendl__fd(char *s, int fd);
void	unset(t_env **env, char **arg);
void	ft_putstr__fd(char *s, int fd);
void	ft_print_export(t_env *env);
size_t	ft__strlen(const char *str);
char	**ft_get_varval(char *arg);
t_env	*ft_getvenv(char **env);
int		ft_envsize(t_env *env);
int		ft_check_id(char *id);
void	ft_putstr(char *str);
char	*get_val(char *line);
char	*get_var(char *line);
void	ft_env(t_env *virt);
void	echo(char **args);

#endif