/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_super_ez.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/11 15:36:45 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/27 16:58:52 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_input_is_two(t_stack *stack_a, int *stats);
static void	solve_input_is_three(t_stack *stack_a, int *stats);
static void	solve_input_is_five(t_stack *stack_a, t_stack *stack_b, int *stats);

void	solve_super_ez(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	int	size;

	size = stack_a->size;
	if (size == 2)
		solve_input_is_two(stack_a, stats);
	else if (size == 3)
		solve_input_is_three(stack_a, stats);
	else if (size == 4 || size == 5)
		solve_input_is_five(stack_a, stack_b, stats);
}

static void	solve_input_is_two(t_stack *stack_a, int *stats)
{
	if (stack_a->top->num > stack_a->top->next->num)
		sa(stack_a, stats);
}

static void	solve_input_is_three(t_stack *stack_a, int *stats)
{
	long long	top;
	long long	middle;
	long long	bottom;

	top = stack_a->top->num;
	middle = stack_a->top->next->num;
	bottom = stack_a->top->prev->num;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack_a, stats);
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack_a, stats);
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack_a, stats);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack_a, stats);
		ra(stack_a, stats);
	}
	else if (top > middle && middle > bottom && top > bottom)
	{
		ra(stack_a, stats);
		sa(stack_a, stats);
	}
}

static void	solve_input_is_five(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	while (stack_a->size > 3)
	{
		rotate_smallest_to_top(stack_a, stats);
		pb(stack_b, stack_a, stats);
	}
	solve_input_is_three(stack_a, stats);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, stats);
}
