/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   convert_to_lst.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/04 21:08:35 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/05 12:47:12 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_duplicate(t_stack *stack, int number);
static bool	out_of_bounds(long long int number);

t_stack	*convert_to_lst(char **argv)
{
	t_num			*node;
	t_stack			*stack_a;

	stack_a = stack_init();
	if (stack_a == NULL)
		return (NULL);
	while (*argv != NULL)
	{
		node = new_node(ft_atoi(*argv));
		if (node == NULL
			|| out_of_bounds(node->num) == true
			|| check_duplicate(stack_a, node->num) == true)
		{
			free(node);
			clear_stack(stack_a);
			return (NULL);
		}
		stack_add_back(stack_a, node);
		argv++;
	}
	return (stack_a);
}

static bool	check_duplicate(t_stack *stack, int number)
{
	t_num	*current_node;
	int		i;

	current_node = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (current_node->num == number)
			return (true);
		current_node = current_node->next;
		i++;
	}
	return (false);
}

static bool	out_of_bounds(long long int number)
{
	if (INT_MIN <= number && number <= INT_MAX)
		return (false);
	else
		return (true);
}
