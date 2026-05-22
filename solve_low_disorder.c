/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_low_disorder.c                               :+:    :+:            */
/*
	+:+                    */
/*   By: andjajas <andjajas@student.codam.nl>
	+#+                     */
/*
	+#+                      */
/*   Created: 2026/05/21 11:14:12 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/21 11:14:12 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_disorder_index(t_stack *stack_a);
static void	rotate_node_to_top(t_stack *stack_a, int index, int *stats);

void	solve_low_disorder(t_stack *stack_a, int *stats)
{
	int	index;
	int	i;

	assign_rank (stack_a);
	index = find_disorder_index(stack_a);
	while (index != -1)
	{
		rotate_node_to_top(stack_a, index, stats);
		sa(stack_a, stats);
		if (index <= stack_a->size / 2)
		{
			i = index;
			while (i--)
				rra(stack_a, stats);
		}
		else
		{
			i = stack_a->size - index;
			while (i--)
				ra(stack_a, stats);
		}
		index = find_disorder_index(stack_a);
	}
}

static int	find_disorder_index(t_stack *stack_a)
{
	t_num	*now;
	int		i;

	now = stack_a->top;
	i = 0;
	while (i < stack_a->size - 1)
	{
		if (now->rank > now->next->rank)
			return (i);
		now = now->next;
		i++;
	}
	return (-1);
}

static void	rotate_node_to_top(t_stack *stack_a, int index, int *stats)
{
	int	ra_needed;
	int	rra_needed;

	ra_needed = index;
	if (ra_needed == 0)
		return ;
	if ((ra_needed) <= stack_a->size / 2)
	{
		while (ra_needed)
		{
			ra(stack_a, stats);
			ra_needed--;
		}
	}
	else
	{
		rra_needed = stack_a->size - ra_needed;
		while (rra_needed)
		{
			rra(stack_a, stats);
			rra_needed--;
		}
	}
}
