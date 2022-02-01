/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:12:11 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/17 20:22:53 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
# define NODES_H

# include <stddef.h>

typedef struct s_node	t_node;

t_node	*node_new(void *data);
t_node	*node_end(t_node *n);
t_node	*node_head(t_node *n);
t_node	*node_iter(t_node *head, size_t n);
size_t	node_count(t_node *head);
void	node_del(t_node *node);
void	node_apply(t_node *head, void (*f)());
void	node_push(t_node **head, t_node *new);
void	node_add(t_node **head, t_node *new);
void	node_swap(t_node **a, t_node **b);
void	node_clear(t_node **head);
void	node_drop(t_node **head);
void	node_pop(t_node **n);

#endif
