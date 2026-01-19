/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:02:17 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/19 13:09:14 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float compute_disorder(t_stack_node *a)
{
    int bad = 0;
    int total = 0;
    t_stack_node *tmp;

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


/* double  compute_disorder(t_stack_node *stack)
{
    t_stack_node    *i;
    t_stack_node    *j;
    double          mistakes;
    double          total_pairs;

    mistakes = 0;
    total_pairs = 0;
    i = stack;
    while (i)
    {
        j = i->next;
        while (j)
        {
            total_pairs++;
            if (i->value > j->value)
                mistakes++;
            j = j->next;
        }
        i = i->next;
    }
    if (total_pairs == 0)
        return (0.0);
    return (mistakes / total_pairs);
}
 */