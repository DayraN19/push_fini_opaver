/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:21:31 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/15 12:21:41 by bastiangran      ###   ########.fr       */
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

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	sort_chunks(t_stack_node **a, t_stack_node **b, int chunk, t_ctrl *c)
{
	int	i;
	int	size;

	i = 0;

	size = stack_size(*a);
	if (size <= 1)
		return ;

	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, c);
			rb(b, c);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b, c);
			i++;
		}
		else
			ra(a, c);
	}
}

int	get_max_bits(t_stack_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
