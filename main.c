/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/13 15:40:37 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_set	settings;
	t_stack	stack_a;
	t_stack	stack_b;
	char	**input;
	int		i;

	(void)argc;
	ft_bzero(&stack_a, sizeof(stack_a));
	ft_bzero(&stack_b, sizeof(stack_b));
	input = ft_supersplit((const char **)argv, ' ');
	if (input == NULL)
	{
		ft_putstr_err("Error\n");
		return (1);
	}
	i = 1;
	i += set_settings(input + i, &settings);
	if (is_valid_input(input + i) == false
		|| convert_to_lst(input + i, &stack_a) == FAILED)
	{
		free_array(input);
		ft_putstr_err("Error\n");
		return (1);
	}
	free_array(input);
	push_swap(&stack_a, &stack_b, settings);
	clear_stack(&stack_a);
	if (settings.bench == false)
	{
		ft_putstr("Bench was not enabled.\n");
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
