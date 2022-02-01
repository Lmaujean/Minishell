/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:33:49 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 16:29:53 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "t_node.h"
#include "ft_string.h"

char	*expand_var(char *s, t_shell *shell);
char	*trim_spaces(char *s);
char	*trim_quotes(char *s);

t_node	*parse(t_node *tok_list, t_shell *shell)
{
	t_node	*it;

	it = tok_list;
	while (it)
	{
		if (*(char *) it->data && !is_op(*(char *) it->data))
		{
			it->data = (void *) trim_spaces((char *) it->data);
			it->data = (void *) expand_var((char *) it->data, shell);
			it->data = (void *) trim_quotes((char *) it->data);
		}
		it = it->next;
	}
	return (tok_list);
}
