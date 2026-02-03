/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:17:22 by bgranier          #+#    #+#             */
/*   Updated: 2026/02/03 11:06:14 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	adaptive_choice(t_stack_node *a, t_ctrl *c)
{
	float	disorder;

	disorder = compute_disorder(a);
	c->count_disorder = disorder;
	if (disorder < 0.2f)
		return (STRAT_SIMPLE);
	if (disorder < 0.5f)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	sort_adaptive(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	if (!a || !*a || !c)
		return ;
	c->executed_strategy = adaptive_choice(*a, c);
	if (stack_size(*a) <= 5)
		c->executed_strategy = STRAT_SIMPLE;
	if (c->executed_strategy == STRAT_SIMPLE)
		sort_simple(a, b, c);
	else if (c->executed_strategy == STRAT_MEDIUM)
		sort_medium(a, b, c);
	else
		sort_complex(a, b, c);
	c->size_a = stack_size(*a);
	c->size_b = stack_size(*b);
}

/* static t_strategy	adaptive_choice(t_stack_node *a, t_ctrl *c)
{
	float	disorder;
	int		size;

	size = stack_size(a);
	disorder = compute_disorder(a);
	c->count_disorder = disorder;
	if (size <= 5)
		return (STRAT_SIMPLE);
	if (disorder < 0.2f)
		return (STRAT_SIMPLE);
	if (disorder < 0.5f)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	sort_adaptive(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	if (!a || !*a || !c)
		return ;
	c->executed_strategy = adaptive_choice(*a, c);
	if (c->executed_strategy == STRAT_SIMPLE)
		sort_simple(a, b, c);
	else if (c->executed_strategy == STRAT_MEDIUM)
		sort_medium(a, b, c);
	else
		sort_complex(a, b, c);
	c->size_a = stack_size(*a);
	c->size_b = stack_size(*b);
} */
