/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_simple.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 20:30:21 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/07 17:02:06 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*find_smallest_node(t_stack *stack_a);
int		calc_rotations(t_num smallest_node);

void	solve_simple(t_stack *stack_a, t_stack *stack_b, int *stats) // work in progress
{
	t_stack	*stack_b;
	t_num	*smallest_node;

	stack_b = stack_init();
	smallest node = find_smallest_node(stack_a);
	calc_rotations(smallest_node);
	free(stack_b);
}

t_num	*find_smallest_node(t_stack *stack_a)
{
	t_num			*current_node;
	t_num			*smallest_node;
	long long int	current_smallest_value;
	int				i;

	current_node = stack_a->top->next;
	smallest_node = stack_a->top;
	current_smallest_value = stack_a->top->num;
	i = 1;
	while (i < stack_a->size)
	{
		if (current_node->num < current_smallest_value)
		{
			current_smallest_value = current_node->num;
			smallest_node = current_node;
		}
		current_node = current_node->next;
		i++;
	}
	return (smallest_node);
}

int	calc_rotations(smallest_node)
{
	
}

// static void	assign_rank(t_stack *stack_a) // work in progress for medium & complex
// {
// 	int			current_rank;
// 	long long	min_value;
// 	t_num		*node_min_value;
// 	t_num		*now;
// 	int			i;

// 	current_rank = 0;
// 	now = stack->top;
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		if (now->num > now->next->num)
// 			min_value = now->num;
// 		else
// 			min_value = now->next->num;
// 		now = now->next;
// 		i++;
// 	}
// }
// TIP from many other peer groups: we need a hardcoded situation for 3- and 5- int string inputs
// add it for the input handling, so you hit the benchmark performance during evaluation!
// we also can make an option that makes the LIVE coding session much easier during evaluation!
// our solve simple here is SELECTION SORT
// selection sort algorithm;
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
