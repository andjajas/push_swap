/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_swap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/03 17:48:30 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/03 20:16:38 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, t_stats *stats)
{
	t_num	*bottom;
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if (!stack->top || !stack->top->next)
		return ;
	bottom = stack->top->prev;
	first = stack->top;
	second = stack->top->next;
	third = stack->top->next->next;
	bottom->next = second;
	first->prev = second;
	first->next = third;
	second->prev = bottom;
	second->next = first;
	third->prev = first;
	stack->top = second;
	write(1, "sa\n", 3);
	stats->sa_count++;
	stats->total_operation_count++;
}

void	sb(t_stack *stack, t_stats *stats)
{
	t_num	*bottom;
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if (!stack->top || !stack->top->next)
		return ;
	bottom = stack->top->prev;
	first = stack->top;
	second = stack->top->next;
	third = stack->top->next->next;
	bottom->next = second;
	first->prev = second;
	first->next = third;
	second->prev = bottom;
	second->next = first;
	third->prev = first;
	stack->top = second;
	write(1, "sb\n", 3);
	stats->sb_count++;
	stats->total_operation_count++;
}
