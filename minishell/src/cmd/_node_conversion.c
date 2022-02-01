/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _node_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:46:01 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/13 16:47:04 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "t_node.h"
#include "types.h"
#include "utils.h"
#include "ft_string.h"

#include <stdlib.h>
#include <stdio.h>

void	nodes_to_mix(t_node *src_nodes, t_node **dst_mix)
{
	char	*data;

	while (src_nodes)
	{
		data = (char *) src_nodes->data;
		if (!data)
			break ;
		if (is_op(*data))
			node_add(dst_mix, node_new((void *) ft_strdup(data)));
		else
		{
			if (src_nodes->next && !is_op(*(char *) src_nodes->next->data))
			{
				add_pair(dst_mix, data, src_nodes->next->data);
				src_nodes = src_nodes->next;
			}
			else
				add_pair(dst_mix, data, "");
		}
		if (!src_nodes || !src_nodes->next)
			break ;
		src_nodes = src_nodes->next;
	}
}

void	print_mix(t_node *cmd_list)
{
	size_t	i;
	t_node	*it;

	i = 1;
	it = cmd_list;
	while (it)
	{
		if (i % 2 != 0)
		{
			printf("[%s][%s]", \
				((t_pair *) it->data)->name, \
				((t_pair *) it->data)->value);
		}
		else
			printf("[%s]", (char *) it->data);
		printf("\n");
		it = it->next;
		i++;
	}
}
