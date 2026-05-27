/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_complex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 18:14:22 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/27 19:02:18 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_bits(t_stack *stack_a);

void	solve_complex(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	int	bits;
	int	ib;
	int	counter_stack_a;
	int	current_bit;

	bits = calculate_bits(stack_a);
	ib = 0;
	while (ib < bits)
	{
		counter_stack_a = stack_a->size;
		while (counter_stack_a--)
		{
			current_bit = (stack_a->top->rank >> ib) & 1;
			if (current_bit == 0)
				pb(stack_b, stack_a, stats);
			else
				ra(stack_a, stats);
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b, stats);
		ib++;
	}
}

static int	calculate_bits(t_stack *stack_a)
{
	int	bits;
	int	max_rank;

	bits = 0;
	max_rank = stack_a->size - 1;
	while ((max_rank >> bits) != 0)
		bits++;
	return (bits);
}
