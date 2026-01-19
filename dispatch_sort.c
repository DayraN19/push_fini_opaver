/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:30:00 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/19 13:46:20 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	dispatch_sort(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	if (!a || !*a || stack_sorted(*a))
	{
		ft_printf("Stack is already sorted or empty. No sorting needed.\n");
		return ;
	}
	if (c->strategy == STRAT_SIMPLE)
		sort_simple(a, b, c);
	else if (c->strategy == STRAT_MEDIUM)
		sort_medium(a, b, c);
	else if (c->strategy == STRAT_COMPLEX)
		sort_complex(a, b, c);
	else if (c->strategy == STRAT_ADAPTIVE)
		sort_adaptive(a, c);
} */
//bon
/* void	dispatch_sort(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	if (!a || !*a || stack_sorted(*a))
		return;
	if (c->strategy == STRAT_SIMPLE)
		sort_simple(a, b, c);
	else if (c->strategy == STRAT_MEDIUM)
		sort_medium(a, b, c);
	else if (c->strategy == STRAT_COMPLEX)
		sort_complex(a, b, c);
	else
		sort_adaptive(a, b, c);
} */

void	dispatch_sort(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	c->count_disorder = compute_disorder(*a);

	if (c->strategy == STRAT_SIMPLE)
	{
		c->executed_strategy = STRAT_SIMPLE;
		sort_simple(a, b, c);
	}
	else if (c->strategy == STRAT_MEDIUM)
	{
		c->executed_strategy = STRAT_MEDIUM;
		sort_medium(a, b, c);
	}
	else if (c->strategy == STRAT_COMPLEX)
	{
		c->executed_strategy = STRAT_COMPLEX;
		sort_complex(a, b, c);
	}
	else
	{
		sort_adaptive(a, b, c);
	}
}

/* void	dispatch_sort(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	if (!c || !a)
		return ;
	if (c->strategy == STRAT_SIMPLE)
		sort_simple(a, b, c);
	else if (c->strategy == STRAT_MEDIUM)
		sort_medium(a, b, c);
	else if (c->strategy == STRAT_COMPLEX)
		sort_complex(a, b, c);
	else if (c->strategy == STRAT_ADAPTIVE)
		sort_adaptive(a, c);
} */

