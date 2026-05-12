/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_rev_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 16:14:13 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/12 14:36:35 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, int *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	stack_a->top = stack_a->top->prev;
	ops_put_operation(RRA, stats);
}

void	rrb(t_stack *stack_b, int *stats)
{
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_b->top = stack_b->top->prev;
	ops_put_operation(RRB, stats);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_a->top = stack_a->top->prev;
	stack_b->top = stack_b->top->prev;
	ops_put_operation(RRR, stats);
}
