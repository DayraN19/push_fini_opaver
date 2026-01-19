#include "push_swap.h"

void    sort_simple(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	int size;
	double  i;

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
}
