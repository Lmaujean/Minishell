/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:35:32 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:36:00 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NODE_H
# define T_NODE_H

typedef struct s_node
{
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

#endif
