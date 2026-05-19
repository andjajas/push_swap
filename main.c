/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/19 15:40:58 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_did_succeed	do_all(char **argv, t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	(void)argc;
	ft_bzero(&stack_a, sizeof(stack_a));
	ft_bzero(&stack_b, sizeof(stack_b));
	if (do_all(argv, &stack_a, &stack_b) == FAILED)
	{
		ft_putstr_err("Error\n");
		return (1);
	}
	return (0);
}

static t_did_succeed	do_all(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	t_set	settings;
	char	**input;
	int		i;

	input = ft_supersplit((const char **)argv, ft_isspace);
	if (input == NULL)
		return (FAILED);
	i = 1;
	i += set_settings(input + i, &settings);
	if (is_valid_input(input + i) == false
		|| convert_to_lst(input + i, stack_a) == FAILED)
	{
		free_array(input);
		return (FAILED);
	}
	free_array(input);
	push_swap(stack_a, stack_b, settings);
	clear_stack(stack_a);
	if (settings.bench == false)
		ft_putstr("Bench was not enabled.\n");
	return (SUCCES);
}

// Check if no arguments are given
// Check for flags, and set enum values for them
// Put everything into a t_num list
// if theres any duplicate numbers or numbers outside of the integer limit,
// or if any number is invalid or if any allocation fails,
// free everything then return 1
// Call the function that andre will use
