/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_assign_chunks.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/22 09:30:53 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/22 09:30:53 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	square_root(int n);

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

static int	square_root(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}
