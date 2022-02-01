/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:26:33 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:39:42 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "t_node.h"

void	node_add(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (head)
	{
		if (!(*head))
		{
			new->prev = NULL;
			*head = new;
		}
		else
		{
			tmp = node_end(*head);
			tmp->next = new;
			new->prev = tmp;
		}
	}
}
