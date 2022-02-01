/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:25:36 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/18 09:56:30 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_node	t_node;
typedef struct s_shell	t_shell;

t_node	*tokenize(char *input, t_shell *shell);
t_node	*parse(t_node *tok_list, t_shell *shell);

#endif
