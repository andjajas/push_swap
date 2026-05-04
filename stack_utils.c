/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/30 15:47:57 by andjajas      #+#    #+#                 */
/*   Updated: 2026/05/04 22:13:27 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_num	*new_node(long long int num)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->num = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack *stack, t_num *new)
{
	t_num	*bottom;

	if (!stack || !new)
		return ;
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
	t_num	*bottom;
	t_num	*now;
	t_num	*next;

	if (!stack)
		return ;
	if (stack->size <= 1)
	{
		free(stack->top);
		free(stack);
		return ;
	}
	bottom = stack->top->prev;
	bottom->next = NULL;
	stack->top->prev = NULL;
	now = stack->top;
	while (now)
	{
		next = now->next;
		free(now);
		now = next;
	}
	free(stack);
}
