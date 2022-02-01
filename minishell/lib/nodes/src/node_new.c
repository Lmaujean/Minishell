/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:27:14 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:38:21 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stdlib.h>

t_node	*node_new(void *data)
{
	t_node	*ret;

	ret = malloc(sizeof(*ret));
	if (ret)
	{
		ret->data = data;
		ret->prev = NULL;
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}
