/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:02:17 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/20 12:52:29 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack_node *a)
{
	int				bad;
	int				total;
	t_stack_node	*tmp;

	bad = 0;
	total = 0;
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			bad++;
		total++;
		tmp = tmp->next;
	}
	if (total == 0)
		return (0.0f);
	return ((float)bad / (float)total);
}
