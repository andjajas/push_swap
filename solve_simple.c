/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_simple.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 20:30:21 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/27 20:29:00 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_rank(t_stack *stack);

void	solve_simple(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	while (stack_a->size)
		pb(stack_b, stack_a, stats);
	while (stack_b->size)
	{
		rotate_biggest_to_top(stack_b, stats, rb, rrb);
		pa(stack_a, stack_b, stats);
	}
}

void	rotate_biggest_to_top(t_stack *stack, int *stats,
			void (*rx)(t_stack *, int *),
			void (*rrx)(t_stack *, int *))
{
	int	r_needed;
	int	rr_needed;

	r_needed = find_highest_rank(stack);
	if (r_needed == 0)
		return ;
	if ((r_needed) <= stack->size / 2)
	{
		while (r_needed)
		{
			rx(stack, stats);
			r_needed--;
		}
	}
	else
	{
		rr_needed = stack->size - r_needed;
		while (rr_needed)
		{
			rrx(stack, stats);
			rr_needed--;
		}
	}
}

static int	find_highest_rank(t_stack *stack)
{
	t_num		*current_node;
	long long	current_highest_rank;
	int			i;
	int			index;

	current_node = stack->top;
	current_highest_rank = current_node->rank;
	i = 0;
	index = 0;
	while (i < stack->size)
	{
		if (current_node->rank > current_highest_rank)
		{
			current_highest_rank = current_node->rank;
			index = i;
		}
		current_node = current_node->next;
		i++;
	}
	return (index);
}
