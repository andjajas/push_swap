/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/08 18:34:25 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_set	settings;
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	(void)argc;
	ft_bzero(&stack_a, sizeof(stack_a));
	ft_bzero(&stack_b, sizeof(stack_b));
	i = 1;
	i += set_settings(argv + i, &settings);
	if (is_valid_input(argv + i) == false
		|| convert_to_lst(argv + i, &stack_a) == FAILED)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	push_swap(&stack_a, &stack_b, settings);
	clear_stack(&stack_a);
	if (settings.bench == false)
	{
		ft_putstr_fd("Bench was not enabled.\n", STDERR_FILENO);
		return (2);
	}
	return (0);
}

// Check if no arguments are given
// Check for flags, and set enum values for them
// Put everything into a t_num list
// if theres any duplicate numbers or numbers outside of the integer limit,
// or if any number is invalid or if any allocation fails,
// free everything then return 1
// Call the function that andre will use
