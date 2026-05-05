/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/05 19:43:20 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	raise_error(void);

int	main(int argc, char **argv)
{
	int					i;
	t_settings			settings;
	t_stack				*stack;

	i = 1;
	settings = set_settings(argc, argv, &i);
	argv += i;
	if (is_valid_input(argv) == false)
	{
		raise_error();
		return (1);
	}
	stack = convert_to_lst(argv);
	if (stack == NULL)
	{
		raise_error();
		return (1);
	}
	push_swap(stack, settings);
	clear_stack(stack);
	if (settings.bench == false)
		printf("Bench was not enabled\n");
	return (0);
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
