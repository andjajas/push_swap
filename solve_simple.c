/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_simple.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 20:30:21 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/12 13:15:01 by andjajas      ########   odam.nl         */
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
