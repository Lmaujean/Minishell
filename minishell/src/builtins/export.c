/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:34:58 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 13:50:20 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"
#include "nodes.h"
#include "types.h"
#include "utils.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

static void	detect_export_type(char const *var, t_shell *shell);
static void	declare_x(t_shell *shell);

int	export(t_shell *shell, char const *args)
{
	char const	**vars = (char const **) ft_split(args, ' ');
	char const	**pvars = vars;

	if (!(*args))
		declare_x(shell);
	else
	{
		while (vars && *vars)
		{
			detect_export_type(*vars, shell);
			vars++;
		}
	}
	free_split((char **) pvars);
	node_add(&shell->ret_list, node_new((void *) intdup(EXIT_SUCCESS)));
	return (1);
}

static void	detect_export_type(char const *var, t_shell *shell)
{
	t_pair	*find;
	char	*value;

	value = ft_strchr(var, '=');
	if (value)
	{
		*value++ = 0;
		set_pair(&shell->env, var, value);
	}
	else
	{
		find = get_pair(shell->var_list, var);
		if (find)
		{
			set_pair(&shell->env, find->name, find->value);
			free_pair(find);
		}
	}
}

static void	declare_x(t_shell *shell)
{
	t_node const	*it = shell->env;
	t_pair			*pair;

	while (it)
	{
		pair = (t_pair *) it->data;
		if (pair->name)
			printf("declare -x %s=%s\n", pair->name, pair->value);
		it = it->next;
	}
}
