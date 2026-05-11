/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_super_ez.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/11 15:36:45 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/11 16:42:37 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_input_is_two(t_stack *stack_a, int *stats)
{
	if (stack_a->top->num > stack_a->top->next->num)
		sa(stack_a, stats);
}

// work in progress:
void	solve_input_is_three(t_stack *stack_a, int *stats)
{
	t_num	*top;
	t_num	*middle;
	t_num	*bottom;

	top = stack_a->top->num;
	middle = stack_a->top->next->num;
	bottom = stack_a->top->prev->num;
	if (top > middle && )
}
/*
we can use extra variables for clarity or keep it minimal with these comparisons:
compare top with middle, middle with bottom, top with bottom.
213 sa, 231 rra, 312 ra, 132 sa ra, 321 sa rra or ra sa
*/