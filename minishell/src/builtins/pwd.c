/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:26:08 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 12:13:06 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "nodes.h"

#include <stdio.h>
#include <stdlib.h>

int	pwd(t_shell *shell, char const *args)
{
	t_pair const	*pair = get_pair(shell->env, "PWD");

	node_add(&shell->ret_list, node_new((void *) intdup(EXIT_SUCCESS)));
	if (!*args && shell && pair)
	{
		printf("%s\n", pair->value);
		return (1);
	}
	return (0);
}
