/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:26:05 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 12:14:57 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "t_node.h"
#include "nodes.h"

#include <stdio.h>
#include <stdlib.h>

int	env(t_shell *shell, char const *args)
{
	t_node const	*it = shell->env;
	t_node			*tmp;
	t_pair			*pair;

	node_add(&shell->ret_list, node_new((void *) intdup(EXIT_SUCCESS)));
	if (!(*args))
	{
		while (it)
		{
			tmp = it->next;
			pair = (t_pair *) it->data;
			if (pair->name)
				printf("%s=%s\n", pair->name, pair->value);
			else
				node_del((t_node *) it);
			it = tmp;
		}
		return (1);
	}
	return (0);
}
