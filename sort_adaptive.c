#include "push_swap.h"

void sort_adaptive(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
    float   disorder;
    int     size;

    if (!a || !*a || !c)
        return;

    size = stack_size(*a);
    disorder = compute_disorder(*a);
    c->count_disorder = disorder;

    if (size <= 5)
    {
        c->executed_strategy = STRAT_SIMPLE;
        sort_simple(a, b, c);
    }
    else if (size <= 100)
    {
        if (disorder < 0.3f)
            c->executed_strategy = STRAT_SIMPLE;
        else
            c->executed_strategy = STRAT_MEDIUM;

        if (c->executed_strategy == STRAT_SIMPLE)
            sort_simple(a, b, c);
        else
            sort_medium(a, b, c);
    }
    else
    {
        c->executed_strategy = STRAT_COMPLEX;
        sort_complex(a, b, c);
    }

    c->size_a = stack_size(*a);
    c->size_b = stack_size(*b);
}


/* void	sort_adaptive(t_stack_node **a, t_stack_node **b, t_ctrl *c)
{
	if (!a || !*a || !c)
		return ;
	float disorder;

	disorder = compute_disorder(*a);
	c->count_disorder = disorder;

	if (disorder < 0.2f)
		sort_simple(a, b, c);
	else if (disorder <= 0.5f)
		sort_medium(a, b, c);
	else
		sort_complex(a, b, c);

} */

/* void    sort_adaptive(t_stack_node **a, t_ctrl *c)
{
int	disorder;

	if (!c || !a || !*a)
		return ;

	disorder = compute_disorder(*a);

	// Choix de stratégie selon le désordre
	if (disorder < 0.2)
		c->strategy = STRAT_SIMPLE;
	else if (disorder <= 0.5)
		c->strategy = STRAT_MEDIUM;
	else
		c->strategy = STRAT_COMPLEX;
}*/




/* {
    double d;

    if (!a || !*a)
        return ;
    d = compute_disorder(*a);

    if (d < 0.2)
        sort_simple(a, b, c);        // pile presque triée
    else if (d < 0.5)
        sort_medium(a, b, c);        // tri moyen (O(n√n))
    else
        sort_complex(a, b, c);       // désordre élevé (O(n log n))
} */