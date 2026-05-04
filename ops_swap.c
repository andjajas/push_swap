/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_swap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/03 17:48:30 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/04 20:38:48 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rewire_ptrs(t_stack *stack);
static bool	swap_or_not(t_stack *stack);

void	sa(t_stack *stack, int *stats)
{
	if (!stack->top || !stack->top->next)
		return ;
	if (stack->top->next->next == stack->top)
		stack->top = stack->top->next;
	else
		rewire_ptrs(stack);
	write(1, "sa\n", 3);
	stats[SA]++;
}

void	sb(t_stack *stack, int *stats)
{
	if (!stack->top || !stack->top->next)
		return ;
	if (stack->top->next->next == stack->top)
		stack->top = stack->top->next;
	else
		rewire_ptrs(stack);
	write(1, "sb\n", 3);
	stats[SB]++;
}

void	ss(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	bool	did_swap_a;
	bool	did_swap_b;

	did_swap_a = swap_or_not(stack_a);
	did_swap_b = swap_or_not(stack_b);
	if (did_swap_a || did_swap_b)
		stats[SS]++;
}

static void	rewire_ptrs(t_stack *stack)
{
	t_num	*bottom;
	t_num	*first;
	t_num	*second;
	t_num	*third;

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

static bool	swap_or_not(t_stack *stack)
{
	t_num	*old_top;

	old_top = stack->top;
	if (stack->top == NULL || stack->top->next == stack->top)
		return (false);
	if (stack->top->next->next == stack->top)
		stack->top = stack->top->next;
	else
		rewire_ptrs(stack);
	if (stack->top != old_top)
		return (true);
	return (false);
}
