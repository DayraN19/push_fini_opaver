/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:21:31 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/20 13:28:10 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d(%d) -> ", stack->value, stack->index);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	move_min_to_top(t_stack_node **a, t_ctrl *c)
{
	t_stack_node	*tmp;
	int				min;
	int				pos;
	int				i;

	tmp = *a;
	min = tmp->index;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (pos <= stack_size(*a) / 2)
		while (pos-- > 0)
			ra(a, c);
	else
		while (pos++ < stack_size(*a))
			rra(a, c);
}
