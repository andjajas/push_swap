/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_medium.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 18:10:54 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/20 21:23:46 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_medium(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	int	i;
	int	j;

	assign_rank(stack_a);
	assign_chunks(stack_a);

	i = 0;
	while (i < stack_a->chunks_needed)
	{
		j = 0;
		while (j < stack_a->chunk_size)
		{
			push_next_in_chunk(stack_a, stack_b, j, stats);
			j++;
		}
		i++;
	}
}

void	push_next_in_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_index,
		int *stats)
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

int	needed_rotations(t_stack *stack_a, int start, int end)
{
	int	ra_needed;
	int	rra_needed;

	if (top_check(stack_a, start, end) == 0)
		return (0);
	ra_needed = forward_scan(stack_a, start, end);
	rra_needed = backward_scan(stack_a, start, end);
	if (ra_needed <= rra_needed)
		return (ra_needed);
	else
		return (-rra_needed);
}

int	top_check(t_stack *stack_a, int start, int end)
{
	t_num	*now;

	now = stack_a->top;
	if (in_chunk(now->rank, start, end))
		return (0);
	else
		return (1);
}

int	forward_scan(t_stack *stack_a, int start, int end)
{
	t_num	*now;
	int		ra_needed;
	int		i;

	now = stack_a->top->next;
	ra_needed = stack_a->size;
	i = 1;
	while (i < stack_a->size)
	{
		if (in_chunk(now->rank, start, end))
		{
			ra_needed = i;
			break ;
		}
		now = now->next;
		i++;
	}
	return (ra_needed);
}

int	backward_scan(t_stack *stack_a, int start, int end)
{
	t_num	*now;
	int		rra_needed;
	int		i;

	now = stack_a->top->prev;
	rra_needed = stack_a->size;
	i = 1;
	while (i < stack_a->size)
	{
		if (in_chunk(now->rank, start, end))
		{
			rra_needed = i;
			break ;
		}
		now = now->prev;
		i++;
	}
	return (rra_needed);
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
	return (i - 1);
}

// using chunk sort for the solve_medium