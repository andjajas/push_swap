#include "push_swap.h"

int find_disorder_index(t_stack *stack_a)
{
	t_num	*now;
	int		i;

	now	= stack_a->top;
	i = 0;
	while (now && now->next)
	{
		if (now->value > now->next->value)
			return i;
		now = now->next;
		i++;
	}
	return -1;
}
// if disorder found at position i >> return i;
// if no disorder is found >> return -1;

void fix_low_disorder(t_stack *stack_a, t_stack *stack_b, int *stats)
{
    int	index;

    while ((index = find_disorder_index(stack_a)) != -1)
    {
        if (index == 0)
            sa(stack_a, stats);
        else if (index == 1)
        {
            ra(stack_a, stats);
            sa(stack_a, stats);
            rra(stack_a, stats);
        }
        else
        {
            rotate_element_to_top(stack_a, index, stats);
            pb(stack_b, stack_a, stats);
            rotate_back_to_original(stack_a, stats);
            pa(stack_a, stack_b, stats);
        }
    }
}
