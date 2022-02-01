#include "cmd.h"
#include "utils.h"
#include "builtins.h"
#include "types.h"
#include "nodes.h"
#include "t_node.h"
#include "ft_string.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

int do_builtin(t_node *it, t_shell *shell)
{
	void    (*fct)(t_shell *, char const *);

	(void)shell;
	fct = get_builtin(((t_pair *)it->data)->name);
	if (fct)
	{
		(*fct)(shell, ((t_pair *)it->data)->value);
		return (1);
	}
	return (0);
}