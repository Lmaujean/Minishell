/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:15:10 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/07 10:27:14 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*free_split(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
		free(*tmp++);
	free(str);
	return (NULL);
}
