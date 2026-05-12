/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_complex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 18:14:22 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/12 11:39:38 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_complex(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	(void)stack_a;
	(void)stack_b;
	if (stats != NULL)
		stats[PA] = 1000;
}

void	convert_num_to_rank()
// this function maybe needed for medium or complex algorithms?
// t_num	*find_smallest_node(t_stack *stack_a)
// {
// 	t_num			*current_node;
// 	t_num			*smallest_node;
// 	long long int	current_smallest_value;
// 	int				i;

// 	current_node = stack_a->top->next;
// 	smallest_node = stack_a->top;
// 	current_smallest_value = stack_a->top->num;
// 	i = 1;
// 	while (i < stack_a->size)
// 	{
// 		if (current_node->num < current_smallest_value)
// 		{
// 			current_smallest_value = current_node->num;
// 			smallest_node = current_node;
// 		}
// 		current_node = current_node->next;
// 		i++;
// 	}
// 	return (smallest_node);
// }
//
// static void	assign_rank(t_stack *stack_a) // work in progress for medium & complex
// {
// 	int			current_rank;
// 	long long	min_value;
// 	t_num		*node_min_value;
// 	t_num		*now;
// 	int			i;
//
// 	current_rank = 0;
// 	now = stack->top;
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		if (now->num > now->next->num)
// 			min_value = now->num;
// 		else
// 			min_value = now->next->num;
// 		now = now->next;
// 		i++;
// 	}
// }
//
// lets try RADIX SORT for the complex algorithm.
// we also can make an option that makes the LIVE coding session much easier during evaluation!

