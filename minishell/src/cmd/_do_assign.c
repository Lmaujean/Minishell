#include "nodes.h"
#include "t_node.h"
#include "cmd.h"
#include "utils.h"
#include "types.h"
#include "ft_string.h"
#include "libft.h"

int	do_assign(t_node *it, t_shell *shell)
{
	size_t	i;
	char **split;

	i = -1;
	split = 0;
	if (check_assign(shell, ((t_pair *)it->data)->name, 0) == 1)
	{
		if (*(((t_pair *)it->data)->value))
			split = ft_split(((t_pair *)it->data)->value, ' ');
		check_assign(shell, ((t_pair *)it->data)->name, 1);
		if (split)
		{
			while (split && split[++i])
				check_assign(shell, split[i], 1);
			free_split(split);
		}
		return (1);
	}
	return (0);
}