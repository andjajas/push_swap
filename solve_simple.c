/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_simple.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 20:30:21 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/05 20:57:42 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_rank(t_stack *stack_a);

void	solve_simple(t_stack *stack_a, int *stats)
{
	t_stack	*stack_b;

	stack_b = stack_init();
	
	free(stack_b);
}

static void	assign_rank(t_stack *stack_a)
{
	int			current_rank;
	long long	min_value;
	t_num		*node_min_value;
	t_num		*now;
	int			i;

	current_rank = 0;
	now = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (now->num > now->next->num)
			min_value = now->num;
		else
			min_value = now->next->num;
		now = now->next;
		i++;
	}
}
