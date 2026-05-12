/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_swap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/03 17:48:30 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/12 14:35:08 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack);

void	sa(t_stack *stack_a, int *stats)
{
	if (stack_a->top == NULL || stack_a->top->next == stack_a->top)
		return ;
	swap(stack_a);
	ops_put_operation(SA, stats);
}

void	sb(t_stack *stack_b, int *stats)
{
	if (stack_b->top == NULL || stack_b->top->next == stack_b->top)
		return ;
	swap(stack_b);
	ops_put_operation(SB, stats);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	if (stack_a->top == NULL || stack_a->top->next == stack_a->top)
		return ;
	if (stack_b->top == NULL || stack_b->top->next == stack_b->top)
		return ;
	swap(stack_a);
	swap(stack_b);
	ops_put_operation(SS, stats);
}

static void	swap(t_stack *stack)
{
	t_num	*bottom;
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if (stack->top->next->next == stack->top)
		stack->top = stack->top->next;
	else
	{
		bottom = stack->top->prev;
		first = stack->top;
		second = stack->top->next;
		third = stack->top->next->next;
		bottom->next = second;
		first->prev = second;
		first->next = third;
		second->prev = bottom;
		second->next = first;
		third->prev = first;
		stack->top = second;
	}
}
