/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/30 15:47:57 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/01 21:35:57 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_num	*add_new_node(t_num *new)
{
	new = malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->num = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_num **stack, t_num *new)
{
	t_num	*tail;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tail = ft_stacklast(*stack);
	tail->next = new;
}

void	stack_clear(t_num **stack, void (*del)(void *))
{
	t_num	*tmp_stack;

	if (!stack || !del)
		return ;
	while (*stack)
	{
		tmp_stack = (*stack)->next;
		ft_stackdelone(*stack, del);
		*stack = tmp_stack;
	}
}
