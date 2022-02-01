/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:38:57 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 13:39:56 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "builtins.h"

void	*get_builtin(char const *cmd)
{
	int			i;
	char const	*names[] = {"exit", "echo", "history", \
		"pwd", "cd", "env", "export", "unset"};
	void const	*funcs[] = {&quit, &echo, &history, \
		&pwd, &cd, &env, &export, &unset};

	i = -1;
	while (names[++i] && i < 8)
		if (!diff(cmd, names[i]))
			return ((int *) funcs[i]);
	return (0);
}
