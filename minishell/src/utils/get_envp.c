/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:33:45 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/14 22:52:51 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_string.h"

#include <stdlib.h>

int	get_envp(t_node **env, char **envp)
{
	char	*name;
	char	*value;

	while (*envp)
	{
		name = ft_strndup(*envp, ft_strchr(*envp, '=') - *envp);
		value = 1 + ft_strchr(*envp, '=');
		set_pair(env, name, value);
		free(name);
		envp++;
	}
	return (1);
}
