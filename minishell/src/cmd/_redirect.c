#include "nodes.h"
#include "t_node.h"
#include "cmd.h"
#include "utils.h"
#include "builtins.h"
#include "types.h"
#include "ft_string.h"
#include "libft.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

static void	_std(t_node *it, t_node *token);
static int put_back(t_node *it, t_node *one, t_node *two);
static int return_error(t_shell *shell, int err, char *op);


int _redirect(t_node *it)
{
	char *op;
	t_node *token;

	token = it->next;
	if (!token)
		return (0);
	op = (char *)token->data;
	if (*op == '>' || *op == '<')
		_std(it, token);
	else if (diff(op, "|"))
		printf("Unknown token [%s]: not handled\n", op);
	return (1);
}

static void _std(t_node *it, t_node *token)
{
	t_node *one;
	t_node *two;

	one = it;
	two = token;
	while(two->next->next && (diff(two->next->next->data, "<") == 0 || diff(two->next->next->data, ">") == 0\
		|| diff(two->next->next->data, ">>") == 0))
	{
		one = token->next;
		two = token->next->next;
	}
	while (put_back(it, one, two) == 1)
	{
		two = one->prev;
		one = two->prev;
	}
}

static int put_back(t_node *it, t_node *one, t_node *two)
{
	char **split;

	if (*((t_pair *)one->data)->name && *((t_pair *)two->next->data)->value)
	{
		if (*((t_pair *)one->data)->value)
			((t_pair *)one->data)->value = my_strjoin(((t_pair *)one->data)->value, " ");
		((t_pair *)one->data)->value = my_strjoin(((t_pair *)one->data)->value, ((t_pair *)two->next->data)->value);
		free(((t_pair *)two->next->data)->value);
		((t_pair *)two->next->data)->value = ft_strdup("");	
	}
	else if (!*((t_pair *)one->data)->name && *((t_pair *)two->next->data)->value)
	{
		split = ft_split(((t_pair *)two->next->data)->value, ' ');
		((t_pair *)one->data)->name = ft_strdup(split[0]);
		((t_pair *)one->data)->value = ft_strdup(((t_pair *)two->next->data)->value + ft_strlen(split[0]) + 1);
		free_split(split);
		free(((t_pair *)two->next->data)->value);
		((t_pair *)two->next->data)->value = ft_strdup("");
	}
	if (one == it)
		return (0);
	return (1);
}

int check_tokens(t_node *it, t_shell *shell)
{
	char *op;

	op = (char *)(it->data);
	if (!*((t_pair *)it->prev->data)->name)
		if (*op == '|' || *op == '&' || *op == ';' || *op == '(' || *op == ')')
			return(return_error(shell, 258, op));
	if (op[0] == '>' && op[1] == '<')
		return(return_error(shell, 258, &op[1]));
	if (op[0] == ';' && (op[1] == ';' || op[1] == '|' || op[1] == '&'))
		return(return_error(shell, 258, &op[1]));
	if (!*((t_pair *)it->next->data)->name)
		if (*op == '<' || *op == '>')
			return(return_error(shell, 258, "newline"));
	return (1);
}

static int return_error(t_shell *shell, int err, char *op)
{
	node_add(&shell->ret_list, node_new((void *) intdup(err)));
	printf("minishell: syntax error near unexpected token '%s'\n", op);
	return (0);
}