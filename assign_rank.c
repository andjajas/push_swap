/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign_rank.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/22 09:31:11 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/26 18:25:57 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_for_assign_rank(t_stack *stack_a);
static int	*sort_for_assign_rank(t_stack *stack_a);

void	assign_rank(t_stack *stack_a)
{
	t_num	*now;
	int		*sorted;
	int		i;
	int		j;

	sorted = sort_for_assign_rank(stack_a);
	if (sorted == NULL)
		return ;
	i = 0;
	while (i < stack_a->size)
	{
		now = stack_a->top;
		j = 0;
		while (j < stack_a->size)
		{
			if (now->num == sorted[i])
				now->rank = i;
			now = now->next;
			j++;
		}
		i++;
	}
	free(sorted);
}

static int	*fill_for_assign_rank(t_stack *stack_a)
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

static int	*sort_for_assign_rank(t_stack *stack_a)
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
