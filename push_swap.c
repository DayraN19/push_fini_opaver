/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:09:55 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/19 11:50:06 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctrl			c;
	t_stack_node	*a = NULL;
	t_stack_node	*b = NULL;
	int				start_arg = 1;

	if (argc < 2)
		return (0);

	c.bench = 0;
	c.strategy = STRAT_ADAPTIVE;

	/* bench */
	if (!ft_strcmp(argv[1], "--bench"))
	{
		c.bench = 1;
		start_arg = 2;
	}

	/* ⚠️ SAUTER TOUS LES FLAGS AVANT LA STACK */
	while (start_arg < argc && is_flag(argv[start_arg]))
		start_arg++;

	if (argc <= start_arg)
		return (0);

	init_stack_a(&a, &argv[start_arg]);
	index_stack(a);

	ctrl_init(&c, a, b);

	/* sélection stratégie (flags seulement) */
	select_strategy(&c, argv);

	dispatch_sort(&a, &b, &c);

	if (c.bench)
		print_bench(&c);

	free_stack(a);
	free_stack(b);
	return (0);
}




//bon de base
/* int	main(int argc, char **argv)
{
	t_ctrl			c;
	t_stack_node	*a = NULL;
	t_stack_node	*b = NULL;
	int				start_arg = 1;

	if (argc < 2)
		return (0);
	c.bench = 0;
	if (!ft_strcmp(argv[1], "--bench"))
	{
		c.bench = 1;
		start_arg = 2;
	}
	if (argc <= start_arg)
		return (0);
	init_stack_a(&a, &argv[start_arg]);
	index_stack(a);
	c.strategy = STRAT_ADAPTIVE;
	ctrl_init(&c, a, b);
	select_strategy(&c, &argv[start_arg]);
	dispatch_sort(&a, &b, &c);
	if (c.bench)
		print_bench(&c);
	free_stack(a);
	free_stack(b);
	return (0);
} */


//dernier pas bon mais presque
/* int	main(int argc, char **argv)
{
	t_ctrl			c;
	t_stack_node	*a = NULL;
	t_stack_node	*b = NULL;
	int				start_arg = 1;

	c.bench = 0;
	if (argc > 1 && ft_strcmp(argv[1], "--bench") == 0)
	{
		c.bench = 1;
		start_arg = 2;
	}

	// flag stratégie
	 if (argc > start_arg)
	{
		if (ft_strcmp(argv[start_arg], "--simple") == 0)
			c.strategy = STRAT_SIMPLE, start_arg++;
		else if (ft_strcmp(argv[start_arg], "--medium") == 0)
			c.strategy = STRAT_MEDIUM, start_arg++;
		else if (ft_strcmp(argv[start_arg], "--complex") == 0)
			c.strategy = STRAT_COMPLEX, start_arg++;
		else if (ft_strcmp(argv[start_arg], "--adaptive") == 0)
			c.strategy = STRAT_ADAPTIVE, start_arg++;
	} 

	if (argc <= start_arg)
		return (0);

	init_stack_a(&a, &argv[start_arg]);
	index_stack(a);
	select_strategy(&c, &argv[start_arg]);
	printf("sorted = %d\n", stack_sorted(a));
	dispatch_sort(&a, &b, &c);
	//  ctrl_init APRES avoir décidé bench + strategy
	ctrl_init(&c, a, b);
	if (c.bench)
		print_bench(&c);
	free_stack(a);
	free_stack(b);
	return (0);
} */
/* int	main(int argc, char **argv)
{
	t_ctrl			c;
	t_stack_node	*a = NULL;
	t_stack_node	*b = NULL;
	int				start_arg = 1;

	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "--bench") == 0)
		{
			c.bench = 1;
			start_arg = 2;
		}
	}
	if (argc > start_arg)
	{
		if (ft_strcmp(argv[start_arg], "--simple") == 0)
		{
			c.strategy = STRAT_SIMPLE;
			start_arg++;
		}
		else if (ft_strcmp(argv[start_arg], "--medium") == 0)
		{
			c.strategy = STRAT_MEDIUM;
			start_arg++;
		}
		else if (ft_strcmp(argv[start_arg], "--complex") == 0)
		{
			c.strategy = STRAT_COMPLEX;
			start_arg++;
		}
		else if (ft_strcmp(argv[start_arg], "--adaptive") == 0)
		{
			c.strategy = STRAT_ADAPTIVE;
			start_arg++;
		}
		else
			c.strategy = STRAT_ADAPTIVE;
	}
	if (argc <= start_arg)
	{
		write(1, "Error: no numbers to sort\n", 27);
		return 1;
	}
	init_stack_a(&a, &argv[start_arg]);
	if (!a)
		return 1;
	index_stack(a);
	ctrl_init(&c, a, b);
	c.first = a;
	c.last = ft_lstlast(a);
	dispatch_sort(&a, &b, &c);
	if (c.bench)
		print_bench(&c);
	free_stack(a);
	free_stack(b);
	return 0;
} */


/* int	main(int argc, char **argv)
{
	t_ctrl			c;
	t_stack_node	*a;
	t_stack_node	*b;
	int				start_arg;

	a = NULL;
	b = NULL;
	c.bench = 0;

	// 1) check --bench
	if (argc > 1 && ft_strcmp(argv[1], "--bench") == 0)
	{
		c.bench = 1;
		start_arg = 2; // les nombres commencent après --bench
	}
	else
		start_arg = 1; // pas de flag, nombres commencent à argv[1]

	// 2) pas de nombres → exit
	if (argc <= start_arg)
		return (0);

	// 3) init stack
	init_stack_a(&a, &argv[start_arg]);
	if (!a)
		return (0);

	index_stack(a);

	// 4) init ctrl
	ctrl_init(&c, a, b);
	c.first = a;
	c.last = ft_lstlast(a);

	// 5) select + dispatch
	select_strategy(&c, &a, &b);
	dispatch_sort(&a, &b, &c);

	// 6) bench
	if (c.bench)
		print_bench(&c);

	// 7) cleanup
	free_stack(a);
	free_stack(b);
	return (0);
} */
