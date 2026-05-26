/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_needed_rotations.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/22 09:30:32 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/26 18:21:28 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	top_check(t_stack *stack_a, int start, int end);
static int	forward_scan(t_stack *stack_a, int start, int end);
static int	backward_scan(t_stack *stack_a, int start, int end);
static bool	in_chunk(unsigned int rank, int start, int end);

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

static int	top_check(t_stack *stack_a, int start, int end)
{
	t_num	*now;

	now = stack_a->top;
	if (in_chunk(now->rank, start, end))
		return (0);
	else
		return (1);
}

static int	forward_scan(t_stack *stack_a, int start, int end)
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

static int	backward_scan(t_stack *stack_a, int start, int end)
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

static bool	in_chunk(unsigned int rank, int start, int end)
{
	if ((int)rank >= start && (int)rank <= end)
		return (true);
	return (false);
}
