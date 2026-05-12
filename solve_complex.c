/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_complex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 18:14:22 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/12 21:16:48 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_complex(t_stack *stack_a, t_stack *stack_b, int *stats)
{
	int	bit_position;

	assign_rank(stack_a);
	while()
	{
		while()
		{
			
		}
	}
}

int	*fill_for_assign_rank(t_stack *stack_a)
{
	t_num	*now;
	int		*nums;
	int		i;

	nums = malloc(sizeof(int) * stack_a->size);
	if (nums == NULL)
		return (NULL);
	now = stack_a->top;
	i = 0;
	while (i < stack_a->size)
	{
		nums[i] = (int)now->num;
		now = now->next;
		i++;
	}
	return (nums);
}

int	*sort_for_assign_rank(t_stack *stack_a)
{
	int	*nums;
	int	tmp;
	int	i;
	int	j;

	nums = fill_for_assign_rank(stack_a);
	if (nums == NULL)
		return (NULL);
	i = 0;
	while (i < stack_a->size - 1)
	{
		j = 0;
		while (j < stack_a->size - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (nums);
}

void	assign_rank(t_stack *stack_a)
{
	t_num	*now;
	int		*nums;
	int		i;
	int		j;

	nums = sort_for_assign_rank(stack_a);
	if (nums == NULL)
		return ;
	i = 0;
	while (i < stack_a->size)
	{
		now = stack_a->top;
		j = 0;
		while (j < stack_a->size)
		{
			if (now->num == nums[i])
				now->rank = i;
			now = now->next;
			j++;
		}
		i++;
	}
	free(nums);
}

// add to README vincent en thijn
// void	convert_num_to_rank()
// this function maybe needed for medium or complex algorithms?
// t_num	*find_smallest_node(t_stack *stack_a)
// {
// 	t_num			*current_node;
// 	t_num			*smallest_node;
// 	long long	current_smallest_value;
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

