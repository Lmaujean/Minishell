/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:34:48 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 13:40:37 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "libft.h"
#include "utils.h"
#include "nodes.h"

#include <stdio.h>
#include <stdlib.h>

int	echo(t_shell *shell, char const *args)
{
	if (args && shell)
	{
		if (ft_strncmp(args, "-n ", 3) == 0)
			printf("%s\n", args + 3);
		else
			printf("%s\n", args);
	}
	else
		printf("\n");
	node_add(&shell->ret_list, node_new((void *) intdup(EXIT_SUCCESS)));
	return (1);
}
