/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_medium.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 18:10:54 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/14 18:18:23 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_medium(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	assign_rank(stack_a);
	assign_chunks(stack_a);
}

void	push_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_index, int *stats)
{
	t_num			*now;
	unsigned int	rank;
	int				start;
	int				end;
	int				i;
	int				ra_needed;
	int				rra_needed;

	now = stack_a->top;
	rank = now->rank;
	start = stack_a->chunk_starts[chunk_index];
	end = stack_a->chunk_ends[chunk_index];
	i = 0;
	while (i < stack_a->size)
	{
		if (in_chunk(rank, start, end))
			ra_needed = i;
		now = stack_a->top->next;
		i++;
	}
	while (i < stack_a->size)
	{
		if (in_chunk(rank, start, end))
			rra_needed = i;
		now = stack_a-top->prev;
		i++;
	}
	if (ra_needed <= rra_needed)
		return (ra_needed)
	else
		return (-rra_needed)
}

int	needed_rotations(t_stack *stack_a, int start, int end)
{
	t_num			*now;
	int 			ra_needed;
	int				rra_needed;
	int				i;

	now = stack_a->top;
	ra_needed = 0;
	if (in_chunk(now->rank, start, end))
		return (0);
	now = stack_a->top->next;
	i = 1;
	while (i < stack_a->size)
	{
		if (in_chunk(now->rank, start, end))
		{
			ra_needed = i;
			break;
		}
		now = now->next;
		i++;
	}
	now = stack_a->top->prev;
	rra_needed = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (in_chunk(now->rank, start, end))
		{
			rra_needed = i;
			break;
		}
		now = now->prev;
		i++;
	}
	if (ra_needed <= rra_needed)
		return (ra_needed);
	return (-rra_needed);
}

bool	in_chunk(unsigned int rank, int start, int end)
{
	if (rank >= start && rank <= end)
		return (true);
	return (false);
}

void	assign_chunks(t_stack *stack_a)
{
	int	i;

	stack_a->chunks_needed = square_root(stack_a->size);
	stack_a->chunk_size = stack_a->size / stack_a->chunks_needed;
	stack_a->chunk_starts = malloc(sizeof(int) * stack_a->chunks_needed);
	if (stack_a->chunk_starts == NULL)
		return ;
	stack_a->chunk_ends = malloc(sizeof(int) * stack_a->chunks_needed);
	if (stack_a->chunk_ends == NULL)
	{
		free(stack_a->chunk_starts);
		return ;
	}
	i = 0;
	while (i < stack_a->chunks_needed - 1)
	{
		stack_a->chunk_starts[i] = i * stack_a->chunk_size;
		stack_a->chunk_ends[i] = (i + 1) * stack_a->chunk_size - 1;
		i++;
	}
	if (i == stack_a->chunks_needed - 1)
	{
		stack_a->chunk_starts[i] = i * stack_a->chunk_size;
		stack_a->chunk_ends[i] = stack_a->size - 1;
	}
}

int	square_root(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1)
}

// using chunk sort for the solve_medium