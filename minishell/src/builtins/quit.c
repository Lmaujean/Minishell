/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:59:15 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 10:14:01 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int	quit(t_shell *shell, char const *args)
{
	(void)args;
	printf("exit\n");
	free_shell(shell);
	exit(EXIT_SUCCESS);
	return (0);
}
