#include "../../builtins.h"

void	export(t_env *env, char **args)
{
	t_env *tmp;

	tmp = env;
	if (!args[1])
	{
		while (tmp != NULL)
		{
			ft_putstr_fd("declare -x\n", 1);
			tmp = tmp->next;
		}
	}
}
