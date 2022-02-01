/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:30:51 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/26 16:31:48 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_nonstd.h"

void	ft_puts(char const *s)
{
	ft_putendl_fd(s, STDOUT_FILENO);
}
