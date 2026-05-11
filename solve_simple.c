/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_simple.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 20:30:21 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/11 20:09:56 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index_smallest(t_stack *stack_a);
void	rotate_smallest_to_top(t_stack	*stack, int *stats);

void	solve_simple(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	while (stack_a->size)
	{
		rotate_smallest_to_top(stack_a, stats);
		pb(stack_b, stack_a, stats);
	}
	while (stack_b->size)
		pa(stack_a, stack_b, stats);
}

void	rotate_smallest_to_top(t_stack	*stack, int *stats)
{
	int	ra_needed;
	int	rra_needed;

	ra_needed = find_index_smallest(stack);
	if (ra_needed == 0)
		return ;
	if ((ra_needed) <= stack->size / 2)
	{
		while (ra_needed)
		{
			ra(stack, stats);
			ra_needed--;
		}
	}
	else
	{
		rra_needed = stack->size - ra_needed;
		while (rra_needed)
		{
			rra(stack, stats);
			rra_needed--;
		}
	}
}

int	find_index_smallest(t_stack *stack_a)
{
	t_num			*current_node;
	long long int	current_smallest_value;
	int				i;
	int				index;

	current_node = stack_a->top;
	current_smallest_value = stack_a->top->num;
	i = 0;
	index = i;
	while (i < stack_a->size)
	{
		if (current_node->num < current_smallest_value)
		{
			current_smallest_value = current_node->num;
			index = i;
		}
		current_node = current_node->next;
		i++;
	}
	return (index);
}

// This solve_simple uses: SELECTION SORT algorithm;
// assign ranks (how?)... but not needed in selection sort
// find the smallest value in stack_a (how?)...
// define a variable current_smallest_value, we will search for it.
// at the start set the current_smallest_value to the value of the top node.
// loop through the whole list once,
// go to the next node, if value of node is smaller than current_smallest_value,
// change that value to the value of that node, else move on to the next,
// increment iterator and the counter.
// (circle=stop when back at start/remember the start before start loop),
// make calc_rotations() to detemine how many rotations needed to put smallest to top
// use a counter so you know when you find the smallest value, how many rotations are needed,
// to bring it to the top later.
// then use rotating or reverse rotating to bring smallest_rank to the top of stack_a,
// when smallest_rank is at the top of stack_a, push it to stack_b,
// (find again the smallest rank in a, push it to b),
// repeat until all or almost all are in b,
// in b they are reverse sorted,
// then push every top node of stack_b back to stack_a and stack_a will be sorted
// we got a ptr to stack_a from function argument
// we got the stack->size via the ptr to stack_a
// we got the stack->top via the ptr to stack_a
// we got the top->num, top->rank, top->prev, top-next via the stack->top
// we need an iterator to move through the list;
// we need a variable to store the current_minimum_value (set it to the value of first node at start)
// we need a start variable pointing to the start node, so we know where the end is, since we use circular
// we need a counter to track how many rotations are needed.
// we need the operations: ra, rra, pb, pa;
