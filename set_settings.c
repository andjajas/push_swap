/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   set_settings.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/05 19:49:29 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool			get_bench(const char *argument);
static t_e_strategy	get_strategy(const char *argument);

t_settings	set_settings(int argc, char **argv, int *i)
{
	t_settings	set;
	bool		flagged;

	set.strategy = UNSET;
	set.bench = false;
	flagged = true;
	while (*i < argc && flagged == true)
	{
		flagged = false;
		if (set.strategy == UNSET)
		{
			set.strategy = get_strategy(argv[*i]);
			if (set.strategy != UNSET)
				flagged = true;
		}
		if (set.bench == false)
		{
			set.bench = get_bench(argv[*i]);
			if (set.bench == true)
				flagged = true;
		}
		if (flagged == true)
			(*i)++;
	}
	return (set);
}

static bool	strmatch(const char *a, const char *b)
{
	while (*a != '\0' || *b != '\0')
	{
		if (*a != *b)
			return (false);
		a++;
		b++;
	}
	return (true);
}

static bool	get_bench(const char *argument)
{
	if (strmatch(argument, "--bench") == true)
		return (true);
	else
		return (false);
}

static t_e_strategy	get_strategy(const char *argument)
{
	if (strmatch(argument, "--adaptive") == true)
		return (ADAPTIVE);
	else if (strmatch(argument, "--simple") == true)
		return (SIMPLE);
	else if (strmatch(argument, "--medium") == true)
		return (MEDIUM);
	else if (strmatch(argument, "--complex") == true)
		return (COMPLEX);
	else
		return (UNSET);
}
