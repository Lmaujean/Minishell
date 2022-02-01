/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:31:59 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 12:05:31 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "nodes.h"
#include "t_node.h"

#include <stdlib.h>

void	free_pair(t_pair *pair)
{
	free(pair->name);
	pair->name = 0;
	free(pair->value);
	pair->value = 0;
}

void	free_list(t_node **list)
{
	if (*list)
		node_apply(*list, &free_pair);
	node_clear(list);
}

void	free_mix(t_node **mix)
{
	t_node	*it;
	size_t	i;

	it = *mix;
	i = 1;
	while (it)
	{
		if (i % 2)
			free_pair(it->data);
		i++;
		it = it->next;
	}
	node_clear(mix);
}

void	free_shell(t_shell *shell)
{
	if (shell->input)
		free(shell->input);
	free_list(&shell->env);
	free_list(&shell->var_list);
	free_mix(&shell->cmd_list);
	node_clear(&shell->ret_list);
}
