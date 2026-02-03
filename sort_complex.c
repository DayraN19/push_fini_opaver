/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:22:57 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/20 13:23:52 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, c);
			else
				pb(a, b, c);
			j++;
		}
		while (*b)
			pa(a, b, c);
		i++;
	}
}
