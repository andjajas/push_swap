/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   set_settings.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/08 15:05:52 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool			get_bench_flag(const char *argument);
static t_e_strategy	get_strategy_flag(const char *argument);

t_set	set_settings(char ***argv)
{
	t_set	set;
	bool	flagged;

	set.strategy = UNSET;
	set.bench = false;
	flagged = true;
	while (**argv != NULL && flagged == true)
	{
		flagged = false;
		if (set.strategy == UNSET)
		{
			set.strategy = get_strategy_flag(**argv);
			if (set.strategy != UNSET)
				flagged = true;
		}
		if (set.bench == false)
		{
			set.bench = get_bench_flag(**argv);
			if (set.bench == true)
				flagged = true;
		}
		if (flagged == true)
			(*argv)++;
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

static bool	get_bench_flag(const char *argument)
{
	if (strmatch(argument, "--bench") == true)
		return (true);
	else
		return (false);
}

static t_e_strategy	get_strategy_flag(const char *argument)
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
