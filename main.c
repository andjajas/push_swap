/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/01 21:11:40 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	raise_error(void);
static int	get_strategy(const char *argument);
static bool strmatch(const char *a, const char *b);

int	main(int argc, char **argv)
{
	int strategy;
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		i++;
	}
	if (i == argc)
	{
		raise_error();
		return (1);
	}
	strategy = get_strategy(argv[1]);
	if (strategy != -1)
		i++;
	while (i < argc)
	{
		if (ft_isvalidnumber(argv[i]) == false)
		{
			raise_error();
			return (1);
		}
		i++;
	}
	printf("Strategy = %d\n", strategy);
	return (0);
}

static void	raise_error(void)
{
	ft_putstr("Error\n");
}

static bool strmatch(const char *a, const char *b)
{
	while (*a != '\0' && *b != '\0')
	{
		if (*a != *b)
			return (false);
		a++;
		b++;
	}
	return (true);
}

static int	get_strategy(const char *argument)
{
	if (strmatch(argument, "--adaptive") == true)
		return (0);
	else if (strmatch(argument, "--simple") == true)
		return (1);
	else if (strmatch(argument, "--medium") == true)
		return (2);
	else if (strmatch(argument, "--complex") == true)
		return (3);
	else
		return (-1);
}


// Check if no arguments are given
// Check for flags, and set enum values for them
// Put everything into a t_num list
// If any number is invalid or if any allocation fails, free everything then
// return 1
// Call the function that andre will use
