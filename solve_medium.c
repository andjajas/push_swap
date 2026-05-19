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

void	assign_chunks(stack_a)
{
	int	stack_a_size;
	int	chunks_needed;

	stack_a_size = stack_a->size;
	chunks_needed = square_root(stack_a_size);
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