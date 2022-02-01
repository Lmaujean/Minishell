/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:57:00 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/17 20:12:10 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stdlib.h>

void	node_del(t_node *node)
{
	if (node)
	{
		if (!node->prev)
		{
			if (node->next)
				node->next->prev = NULL;
		}
		else if (!node->next)
			node->prev->next = NULL;
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		free(node->data);
		free(node);
	}
}
