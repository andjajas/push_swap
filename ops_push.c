/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/03 15:47:09 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/03 15:47:09 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	t_num	*node;

	node = stack_pop_top(stack_b);
	if (!node)
		return ;
	stack_add_front(stack_a, node);
	write(1, "pa\n", 3);
	stats->pa_count++;
	stats->total_operation_count++;
}

void	pb(t_stack *stack_b, t_stack *stack_a, t_stats *stats)
{
	t_num	*node;

	node = stack_pop_top(stack_a);
	if (!node)
		return ;
	stack_add_front(stack_b, node);
	write(1, "pb\n", 3);
	stats->pb_count++;
	stats->total_operation_count++;
}

t_num	*stack_pop_top(t_stack *stack)
{
	t_num	*node_pop;
	t_num	*bottom;
	t_num	*new_top;

	if (!stack->top)
		return (NULL);
	if (stack->top->next == stack->top)
	{
		node_pop = stack->top;
		stack->top = NULL;
		stack->size = 0;
	}
	else
	{
		node_pop = stack->top;
		bottom = stack->top->prev;
		new_top = stack->top->next;
		bottom->next = new_top;
		new_top->prev = bottom;
		stack->top = new_top;
		stack->size--;
	}
	node_pop->next = NULL;
	node_pop->prev = NULL;
	return (node_pop);
}

void	stack_add_front(t_stack *stack, t_num *node)
{
	t_num	*bottom;

	if (!stack || !node)
		return ;
	if (stack->top == NULL)
	{
		stack->top = node;
		node->prev = node;
		node->next = node;
		stack->size++;
	}
	else
	{
		bottom = stack->top->prev;
		node->prev = bottom;
		node->next = stack->top;
		bottom->next = node;
		stack->top->prev = node;
		stack->top = node;
		stack->size++;
	}
}
