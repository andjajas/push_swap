/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   push_swap.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/05 16:19:19 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/07 16:44:22 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			clear_array(int *array, size_t n);
static t_e_strategy	get_strategy(float disorder);
static float		calculate_disorder(t_stack *stack);

void	push_swap(t_stack *stack_a, t_stack *stack_b, t_set settings)
{
	int				stats[11];
	float			disorder;
	t_e_strategy	strategy;

	clear_array(stats, sizeof(stats) / sizeof(int));
	disorder = calculate_disorder(stack_a);
	if (settings.strategy == UNSET)
		settings.strategy = ADAPTIVE;
	strategy = settings.strategy;
	if (strategy == ADAPTIVE)
		strategy = get_strategy(disorder);
	if (strategy == SIMPLE)
		solve_simple(stack_a, stack_b, stats);
	else if (strategy == MEDIUM)
		solve_medium(stack_a, stack_b, stats);
	else if (strategy == COMPLEX)
		solve_complex(stack_a, stack_b, stats);
	if (settings.bench == true)
		print_bench(disorder, settings.strategy, stats);
}

static void	clear_array(int *array, size_t n)
{
	while (n > 0)
	{
		*array = 0;
		array++;
		n--;
	}
}

static t_e_strategy	get_strategy(float disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	else if (disorder < 0.5)
		return (MEDIUM);
	else
		return (COMPLEX);
}

static float	calculate_disorder(t_stack *stack)
{
	int		total_pairs;
	int		mistakes;
	int		i;
	t_num	*this_node;
	t_num	*next_node;

	total_pairs = stack->size - 1;
	mistakes = 0;
	i = 0;
	this_node = stack->top;
	while (i < total_pairs)
	{
		next_node = this_node->next;
		if (this_node->num > next_node->num)
			mistakes++;
		this_node = next_node;
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}
