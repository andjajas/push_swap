/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_rev_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 16:14:13 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/05 18:19:48 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, int *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	stack_a->top = stack_a->top->prev;
	write(1, "rra\n", 4);
	stats[RRA]++;

}

void	rrb(t_stack *stack_b, int *stats)
{
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_b->top = stack_b->top->prev;
	write(1, "rrb\n", 4);
	stats[RRB]++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_a->top = stack_a->top->prev;
	stack_b->top = stack_b->top->prev;
	write(1, "rrr\n", 4);
	stats[RRR]++;
}
