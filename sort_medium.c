/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:54:28 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/19 12:56:27 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	int	size;
	int	chunk;

	if (!a || !*a)
		return ;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_simple(a, b, c);
		return ;
	}

	chunk = get_chunk_size(size);
	push_chunks(a, b, c, chunk);
	push_back(a, b, c);

	c->size_a = stack_size(*a);
	c->size_b = stack_size(*b);
}
