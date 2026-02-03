/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:56:51 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/20 12:56:52 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

void	push_chunks(t_stack_node **a, t_stack_node **b, t_ctrl *c, int chunk)
{
	int	i;
	int	target;

	i = 0;
	target = chunk;
	while (*a)
	{
		if ((*a)->index < target)
		{
			pb(a, b, c);
			i++;
			if (i == target)
				target += chunk;
		}
		else
			ra(a, c);
	}
}

t_stack_node	*find_max(t_stack_node *b)
{
	t_stack_node	*max;

	max = b;
	while (b)
	{
		if (b->index > max->index)
			max = b;
		b = b->next;
	}
	return (max);
}

void	push_back(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	t_stack_node	*max;
	int				pos;
	int				size;

	while (*b)
	{
		max = find_max(*b);
		pos = get_position(*b, max);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while (*b != max)
				rb(b, c);
		}
		else
		{
			while (*b != max)
				rrb(b, c);
		}
		pa(a, b, c);
	}
}

int	get_position(t_stack_node *stack, t_stack_node *node)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == node)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
