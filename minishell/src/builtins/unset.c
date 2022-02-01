/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:35:25 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 12:14:37 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "nodes.h"
#include "libft.h"

#include <stdlib.h>

int	unset(t_shell *shell, char const *args)
{
	t_pair	*find;
	char	**vars;
	int		i;

	if (*args)
	{
		i = -1;
		vars = ft_split(args, ' ');
		while (vars && vars[++i])
		{
			find = get_pair(shell->env, vars[i]);
			if (!find)
				find = get_pair(shell->var_list, vars[i]);
			if (find)
				free_pair(find);
		}
		free_split(vars);
	}
	node_add(&shell->ret_list, node_new((void *) intdup(EXIT_SUCCESS)));
	return (1);
}
