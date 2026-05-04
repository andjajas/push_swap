/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/04 19:19:06 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	raise_error(void);

int	main(int argc, char **argv)
{
	int					i;
	struct s_settings	settings;

	i = 1;
	settings = set_settings(argc, argv, &i);
	if (is_valid_input(argv + i) == false)
	{
		raise_error();
		return (1);
	}
	printf("Strategy = %d\n", settings.strategy);
	printf("Bench = %s\n", settings.bench ? "true" : "false");
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
