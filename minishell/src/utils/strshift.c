/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strshift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:28:02 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 16:28:31 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strshift(char *str, char c)
{
	while (*str == c)
		str++;
	return (str);
}
