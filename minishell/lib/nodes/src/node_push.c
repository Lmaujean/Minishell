/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:26:49 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:38:42 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stddef.h>

void	node_push(t_node **head, t_node *new)
{
	if (new)
	{
		new->next = *head;
		new->prev = 0;
		if (*head)
			(*head)->prev = new;
		*head = new;
	}
}
