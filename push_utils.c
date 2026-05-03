#include "push_swap.h"

void	stack_add_front(t_stack *stack, t_num *new)
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
		stack->top = new;
		stack->size++;
	}
}

t_num	stack_pop_top(t_stack *stack, t_num *top)
{
}