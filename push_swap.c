/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 16:19:19 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/21 18:53:55 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	calculate_disorder(t_stack *stack);
static void		solve_strategy(t_stack *stack_a, t_stack *stack_b, int *stats,
					t_e_strategy strategy);

void	push_swap(t_stack *stack_a, t_stack *stack_b, t_set settings)
{
	int				stat_array[11];
	int				*stats;
	float			disorder;

	if (settings.bench == true)
	{
		ft_bzero(stat_array, sizeof(stat_array));
		stats = stat_array;
	}
	else
		stats = NULL;
	disorder = calculate_disorder(stack_a);
	if (settings.strategy == UNSET)
		settings.strategy = ADAPTIVE;
	if (settings.strategy == ADAPTIVE)
		solve_strategy(stack_a, stack_b, stats, get_strategy(disorder));
	else
		solve_strategy(stack_a, stack_b, stats, settings.strategy);
	if (settings.bench == true)
		print_bench(disorder, settings.strategy, stats);
}

t_e_strategy	get_strategy(float disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	else if (disorder < 0.5)
		return (MEDIUM);
	else
		return (COMPLEX);
}

static void	solve_strategy(t_stack *stack_a, t_stack *stack_b, int *stats,
			t_e_strategy strategy)
{
	if (stack_a->size <= 5)
		solve_super_ez(stack_a, stack_b, stats);
	else if (strategy == SIMPLE)
		solve_simple(stack_a, stack_b, stats);
	else if (strategy == MEDIUM)
		solve_medium(stack_a, stack_b, stats);
	else if (strategy == COMPLEX)
		solve_complex(stack_a, stack_b, stats);
}

static float	calculate_disorder(t_stack *stack)
{
	int		total_pairs;
	int		mistakes;
	int		i;
	t_num	*this_node;
	t_num	*next_node;

	if (stack->size < 2)
		return ((float) 0);
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
