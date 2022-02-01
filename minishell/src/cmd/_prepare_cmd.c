#include "cmd.h"
#include "utils.h"
#include "types.h"
#include "nodes.h"
#include "t_node.h"
#include "ft_string.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

/*	CACHEES DANS "_node_conversion"	*/
void	nodes_to_mix(t_node *src_nodes, t_node **dst_mix);
void	print_mix(t_node *cmd_list);
/*	pas dans un header car elles sont qu'un transitionnaire pour l'exec	*/

static t_node *clarify_mix(t_node *cmd_list);
static void replace_assign(t_node *it);
static int is_assign(char * str);

int	prepare_cmd(t_shell *shell)
{
	t_node *mix = 0;
	t_node *it;
	size_t	i;
	int 	ret;

	nodes_to_mix(shell->cmd_list, &mix);
	node_clear(&shell->cmd_list);
	i = 1;
	it = mix;
	ret = 1;
	while (it && ret)
	{
		if (i % 2)
			ret = _redirect(it);
		else if (i % 2 == 0 && check_tokens(it, shell) == 0)
		{
			free_mix(&mix);
			return (0);
		}
		it = it->next;
		i++;
	}
	shell->cmd_list = clarify_mix(mix);
	return (1);
}

static t_node *clarify_mix(t_node *cmd_list)
{
	size_t	i;
	t_node	*it;

	i = 1;
	it = cmd_list;
	while (it)
	{
		if (i % 2 != 0 && is_assign(((t_pair *)it->data)->name))
			replace_assign(it);
		it = it->next;
		i++;
	}
	return (cmd_list);
}

static void replace_assign(t_node *it)
{
	char const	*str = (char const *)((t_pair *)it->data)->value;
	char 		**split;
	char 		**tmp;
	char const  *rest = 0;
	size_t 		pos;

	split = ft_split(str, ' ');
	tmp = split;
	pos = 0;
	while (*tmp)
	{
		pos += ft_strlen(*tmp) + 1;
		if (!is_assign(*tmp))
		{
			rest = ft_strdup(str + pos);
			free_pair((t_pair *)it->data);
			((t_pair *)it->data)->name = ft_strdup(*tmp);
			((t_pair *)it->data)->value = ft_strdup(rest);
			break;
		}
		tmp++;
	}
	free((void *)rest);
	free_split(split);
}

static int is_assign(char * str)
{
	char		*value;

	value = var_end(str);
	if (*value == '=' && value != str)
		return (1);
	return (0);
}

