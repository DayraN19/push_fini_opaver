/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:02:27 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/16 15:54:30 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_ctrl *c)
{
	if (!c)
		return ;
	dprintf(2, "\n========== BENCH ==========\n");
	dprintf(2, "Operations executed: %d\n", c->count_op);
	dprintf(2, "RA operations: %d\n", c->count_ra);
	dprintf(2, "RB operations: %d\n", c->count_rb);
	dprintf(2, "RR operations: %d\n", c->count_rr);
	dprintf(2, "RRA operations: %d\n", c->count_rra);
	dprintf(2, "RRB operations: %d\n", c->count_rrb);
	dprintf(2, "RRR operations: %d\n", c->count_rrr);
	dprintf(2, "PA operations: %d\n", c->count_pa);
	dprintf(2, "PB operations: %d\n", c->count_pb);
	dprintf(2, "SA operations: %d\n", c->count_sa);
	dprintf(2, "SB operations: %d\n", c->count_sb);
	dprintf(2, "SS operations: %d\n", c->count_ss);
	dprintf(2, "Stack A size: %d\n", c->size_a);
	dprintf(2, "Stack B size: %d\n", c->size_b);
	dprintf(2, "Disorder measure: %.2f\n", c->count_disorder);
	
	dprintf(2, "Strategy used: %s", strategy_name(c->strategy));

		if (c->strategy == STRAT_ADAPTIVE)
		{
			// CORRECTION ICI : Bien vérifier les arguments
			dprintf(2, " | %s | %s\n",
				strategy_name(c->executed_strategy),      // Nom (ex: SIMPLE)
				strategy_complexity(c->executed_strategy) // Complexité (ex: O(n²))
			);
		}
		else
		{
			dprintf(2, " | %s\n", strategy_complexity(c->strategy));
		}
		dprintf(2, "===========================\n");
}
