/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 16:11:05 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/11 15:20:27 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	stack_a->top = stack_a->top->next;
	if (stats == NULL)
		write(1, "ra\n", 3);
	else
		stats[RA]++;
}

void	rb(t_stack *stack_b, int *stats)
{
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_b->top = stack_b->top->next;
	if (stats == NULL)
		write(1, "rb\n", 3);
	else
		stats[RB]++;
}

void	rr(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_a->top = stack_a->top->next;
	stack_b->top = stack_b->top->next;
	if (stats == NULL)
		write(1, "rr\n", 3);
	else
		stats[RR]++;
}
