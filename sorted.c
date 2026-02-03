/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:15:20 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/20 13:29:05 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_max(t_stack_node *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

void	sort_3(t_stack_node **a, t_ctrl *c)
{
	int	max;

	if (stack_sorted(*a))
		return ;
	max = get_max(*a);
	if ((*a)->value == max)
		ra(a, c);
	else if ((*a)->next->value == max)
		rra(a, c);
	if ((*a)->value > (*a)->next->value)
		sa(a, c);
}
