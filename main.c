/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/07 18:42:50 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	raise_error(void);

int	main(int _, char **argv)
{
	t_set	settings;
	t_stack	stack_a;
	t_stack	stack_b;

	stack_init(&stack_a);
	stack_init(&stack_b);
	argv++;
	settings = set_settings(&argv);
	if (is_valid_input(argv) == false
		|| convert_to_lst(argv, &stack_a) == FAILED)
	{
		raise_error();
		return (1);
	}
	push_swap(&stack_a, &stack_b, settings);
	clear_stack(&stack_a);
	if (settings.bench == false)
		printf("Bench was not enabled\n");
	return (0);
	(void)_;
}

static void	raise_error(void)
{
	ft_putstr("Error\n");
}

// Check if no arguments are given
// Check for flags, and set enum values for them
// Put everything into a t_num list
// if theres any duplicate numbers or numbers outside of the integer limit,
// or if any number is invalid or if any allocation fails,
// free everything then return 1
// Call the function that andre will use
