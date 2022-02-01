/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:48:24 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/14 19:38:17 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_node		t_node;

typedef struct s_pair
{
	char	*name;
	char	*value;
}	t_pair;

typedef struct s_shell
{
	char	*input;
	t_node	*env;
	t_node	*cmd_list;
	t_node	*ret_list;
	t_node	*var_list;
}	t_shell;

#endif
