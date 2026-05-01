/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   push_swap.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/04/29 12:40:11 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool isvalidnumber(char *s);
// static bool ft_isspace(int c);

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		printf("Nothing to sort!\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (isvalidnumber(argv[i]) == false)
		{
			printf("Not all numbers are valid!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static bool isvalidnumber(char *s)
{
	if (*s == '\0')
		return (false);
	while (ft_isspace(*s) == true)
		s++;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s) == true)
		s++;
	if (*s == '\0')
		return (true);
	else
		return (false);
}

// static bool ft_isspace(int c)
// {
// 	if (c == ' ' || (9 <= c && c <= 13))
// 		return (true);
// 	else
// 		return (false);
// }
