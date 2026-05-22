/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   set_settings.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/08 18:08:31 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool			get_bench_flag(const char *argument);
static t_strategy	get_strategy_flag(const char *argument);

int	set_settings(char **argv, t_set *settings)
{
	bool	flagged;
	int		i;

	settings->strategy = UNSET;
	settings->bench = false;
	flagged = true;
	i = 0;
	while (argv[i] != NULL && flagged == true)
	{
		flagged = false;
		if (settings->strategy == UNSET)
		{
			settings->strategy = get_strategy_flag(argv[i]);
			if (settings->strategy != UNSET)
				flagged = true;
		}
		if (settings->bench == false)
		{
			settings->bench = get_bench_flag(argv[i]);
			if (settings->bench == true)
				flagged = true;
		}
		i++;
	}
	return (i - 1);
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

static t_strategy	get_strategy_flag(const char *argument)
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
