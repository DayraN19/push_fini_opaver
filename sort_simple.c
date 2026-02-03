/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:24:42 by bgranier          #+#    #+#             */
/*   Updated: 2026/02/03 10:51:38 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	int	size;

	if (!a || !*a || !c)
		return ;
	c->executed_strategy = STRAT_SIMPLE;
	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, c);
	}
	else if (size == 3)
		sort_three(a, c);
	else
		sort_five(a, b, c);
	c->size_a = stack_size(*a);
	c->size_b = stack_size(*b);
}

/* void	sort_simple(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	int		size;
	double	i;

	size = stack_size(*a);
	i = compute_disorder(*a);
	if (size <= 1)
	{
		ft_printf("Stack is already sorted or empty. No sorting needed.\n");
		return ;
	}
	if (i == 0)
	{
		return ;
	}
	while (*a)
	{
		move_min_to_top(a, c);
		pb(a, b, c);
	}
	while (*b)
	{
		pa(a, b, c);
	}
} */
