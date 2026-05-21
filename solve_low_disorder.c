/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_low_disorder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/21 11:14:12 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/21 11:14:12 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_disorder_index(t_stack *stack_a)
{
	t_num	*now;
	int		i;

	now = stack_a->top;
	i = 0;
	while (i < stack_a->size - 1)
	{
		if (now->rank > now->next->rank)
			return i;
		now = now->next;
		i++;
	}
	return (-1);
}

// if disorder found at position i >> return i;
// if no disorder is found >> return -1;

void	rotate_element_to_top(t_stack *stack_a, int index, int *stats)
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

void	rotate_back_to_original(t_stack *stack_a, int index, int *stats)
{
	int	ra_needed;
	int	rra_needed;

	ra_needed = stack_a->size - index;
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

void solve_low_disorder(t_stack *stack_a, t_stack *stack_b, int *stats)
{
    int	index;

    while ((index = find_disorder_index(stack_a)) != -1)
    {
        if (index == 0)
            sa(stack_a, stats);
        else if (index == 1)
        {
            ra(stack_a, stats);
            sa(stack_a, stats);
            rra(stack_a, stats);
        }
        else
        {
            rotate_element_to_top(stack_a, index, stats);
            pb(stack_b, stack_a, stats);
            rotate_back_to_original(stack_a, index, stats);
            pa(stack_a, stack_b, stats);
        }
    }
}
