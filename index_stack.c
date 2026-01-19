#include "push_swap.h"

void index_stack(t_stack_node *a)
{
    t_stack_node *i;
    t_stack_node *j;
    int index;

    i = a;
    while (i)
    {
        index = 0;
        j = a;
        while (j)
        {
            if (j->value < i->value)
                index++;
            j = j->next;
        }
        i->index = index;
        i = i->next;
    }
}
