/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_medium.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 18:10:54 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/27 20:04:23 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks(t_stack *stack_a, t_stack *stack_b, int *stats);
static void	push_next_in_chunk(t_stack *stack_a, t_stack *stack_b,
				int chunk_index, int *stats);

void	solve_medium(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	assign_chunks(stack_a);
	push_chunks(stack_a, stack_b, stats);
	solve_simple(stack_a, stack_b, stats);
}

static void	push_chunks(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	int	i;
	int	j;
	int	real_chunk_size;

	i = 0;
	while (i < stack_a->chunks_needed)
	{
		real_chunk_size = stack_a->chunk_ends[i] - stack_a->chunk_starts[i] + 1;
		j = 0;
		while (j < real_chunk_size)
		{
			push_next_in_chunk(stack_a, stack_b, i, stats);
			j++;
		}
		i++;
	}
}

static void	push_next_in_chunk(t_stack *stack_a, t_stack *stack_b,
		int chunk_index, int *stats)
{
	int	rot;
	int	start;
	int	end;

	start = stack_a->chunk_starts[chunk_index];
	end = stack_a->chunk_ends[chunk_index];
	rot = needed_rotations(stack_a, start, end);
	while (rot > 0)
	{
		ra(stack_a, stats);
		rot--;
	}
	while (rot < 0)
	{
		rra(stack_a, stats);
		rot++;
	}
	pb(stack_b, stack_a, stats);
}
