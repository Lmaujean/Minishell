/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:31:42 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/03 07:31:43 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_op(char c)
{
	return (c == '&' || c == '|' || c == '>' || c == '<'
		|| c == '(' || c == ')' || c == ';');
}
