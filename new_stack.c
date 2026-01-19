/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:55:52 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/06 14:32:18 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_stack_bottom:
*	Returns the last element of the stack.
*/
t_stack_node	*get_stack_bottom(t_stack_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_stack_node_before_bottom:
*	Returns the second to last element of the stack.
*/
t_stack_node	*get_stack_before_bottom(t_stack_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* stack_new:
*	Creates a stack elements with the provided value.
*	Returns the newly created stack element.
*/
t_stack_node	*stack_new(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/* add_stack_bottom:
*	Adds an element to the bottom of a stack.
*/
void	stack_add_bottom(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

/* get_stack_size:
*	Returns the number of elements in a stack.
*/
int	get_stack_size(t_stack_node	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}