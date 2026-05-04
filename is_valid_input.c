/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   is_valid_input.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/04 17:59:56 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/04 19:00:40 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_isvalidnumber(const char *s);

bool	is_valid_input(char **argv)
{
	if (*argv == NULL)
		return (false);
	while (*argv != NULL)
	{
		if (ft_isvalidnumber(*argv) == false)
			return (false);
		argv++;
	}
	return (true);
}

static bool	ft_isvalidnumber(const char *s)
{
	while (ft_isspace(*s) == true)
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (ft_strlen(s) > 10)
		return (false);
	if (ft_isdigit(*s) == false)
		return (false);
	s++;
	while (ft_isdigit(*s) == true)
		s++;
	if (*s == '\0')
		return (true);
	else
		return (false);
}
