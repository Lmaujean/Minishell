/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:09:36 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:36:44 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

void	node_apply(t_node *head, void (*f)())
{
	while (head)
	{
		(*f)(head->data);
		head = head->next;
	}
}