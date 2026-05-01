/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/01 14:25:00 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	raise_error(void);
static int	get_strategy(const char *arguement);
static bool strmatch(const char *a, const char *b);

int	main(int argc, char **argv)
{
	int strategy;
	int	i;

	if (argc == 1)
	{
		raise_error();
		return (1);
	}
	i = 1;
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

static int	get_strategy(const char *arguement)
{
	if (strmatch(arguement, "--adaptive") == true)
		return (0);
	else if (strmatch(arguement, "--simple") == true)
		return (1);
	else if (strmatch(arguement, "--medium") == true)
		return (2);
	else if (strmatch(arguement, "--complex") == true)
		return (3);
	else
		return (-1);
}
