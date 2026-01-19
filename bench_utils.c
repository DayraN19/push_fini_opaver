#include "push_swap.h"

const char *strategy_name(int strat)
{
    if (strat == STRAT_SIMPLE)
        return ("SIMPLE");
    if (strat == STRAT_MEDIUM)
        return ("MEDIUM");
    if (strat == STRAT_COMPLEX)
        return ("COMPLEX");
    if (strat == STRAT_ADAPTIVE)
        return ("ADAPTIVE");
    return ("UNKNOWN");
}

const char *strategy_complexity(int strat)
{
    if (strat == STRAT_SIMPLE)
        return ("O(n²)");
    if (strat == STRAT_MEDIUM)
        return ("O(n√n)");
    if (strat == STRAT_COMPLEX)
        return ("O(n log n)");
    if (strat == STRAT_ADAPTIVE)
        return ("?");
    return ("UNKNOWN");
}
