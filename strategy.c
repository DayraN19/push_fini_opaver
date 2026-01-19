#include "push_swap.h"

void	select_strategy(t_ctrl *c, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--simple"))
			c->strategy = STRAT_SIMPLE;
		else if (!ft_strcmp(argv[i], "--medium"))
			c->strategy = STRAT_MEDIUM;
		else if (!ft_strcmp(argv[i], "--complex"))
			c->strategy = STRAT_COMPLEX;
		else if (!ft_strcmp(argv[i], "--adaptive"))
			c->strategy = STRAT_ADAPTIVE;
		i++;
	}
}
