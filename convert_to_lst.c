/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   convert_to_lst.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/04 21:08:35 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/04 22:14:02 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (node == NULL || (node->num < INT_MIN || node->num > INT_MAX))
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
