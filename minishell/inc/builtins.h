/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:07:01 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/07 18:27:57 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_shell	t_shell;

int	quit(t_shell *shell, char const *args);
int	echo(t_shell *shell, char const *args);
int	history(t_shell *shell, char const *args);
int	pwd(t_shell *shell, char const *args);
int	cd(t_shell *shell, char const *args);
int	env(t_shell *shell, char const *args);
int	export(t_shell *shell, char const *args);
int	unset(t_shell *shell, char const *args);

#endif
