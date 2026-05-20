/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/30 15:47:57 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/11 15:49:53 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*new_node(long long num)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack *stack, t_num *new)
{
	t_num	*bottom;

	if (stack->top == NULL)
	{
		stack->top = new;
		new->prev = new;
		new->next = new;
		stack->size++;
	}
	else
	{
		bottom = stack->top->prev;
		new->prev = bottom;
		new->next = stack->top;
		bottom->next = new;
		stack->top->prev = new;
		stack->size++;
	}
}

void	clear_stack(t_stack *stack)
{
	t_num	*now;
	t_num	*next;
	int		i;

	now = stack->top;
	i = 0;
	while (i < stack->size)
	{
		next = now->next;
		free(now);
		now = next;
		i++;
	}
	if (stack->sorted)
		free(stack->sorted);
	ft_bzero(stack, sizeof(t_stack));
}
