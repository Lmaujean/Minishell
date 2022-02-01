/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:08:57 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/11 18:55:06 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BOOL_H
# define T_BOOL_H

typedef enum s_bool
{
	FALSE = 0,
	TRUE = !FALSE
}	t_bool;

#endif