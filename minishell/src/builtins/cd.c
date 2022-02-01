/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:34:44 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 13:40:59 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "libft.h"
#include "nodes.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	cd(t_shell *shell, char const *args)
{
	char	tmp[1024];
	char	*defaut;

	defaut = ft_strjoin("/Users/", (get_pair(shell->env, "USER"))->value);
	if (*args && chdir(args) == 0)
	{
		set_pair(&shell->env, "OLDPWD", (get_pair(shell->env, "PWD"))->value);
		set_pair(&shell->env, "PWD", getcwd(tmp, 1024));
		node_add(&shell->ret_list, node_new((void *) intdup(EXIT_SUCCESS)));
		return (1);
	}
	else if (!*args)
		chdir(defaut);
	else if (chdir(args))
		printf("cd: Not a directory\n");
	free(defaut);
	node_add(&shell->ret_list, node_new((void *) intdup(EXIT_FAILURE)));
	return (0);
}
