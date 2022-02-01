/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:27:42 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:39:04 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stddef.h>

size_t	node_count(t_node *head)
{
	size_t	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
