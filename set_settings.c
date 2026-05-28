/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   set_settings.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 20:42:37 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/26 14:32:08 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool			strmatch(const char *a, const char *b);
static enum e_flag	get_strategy_flag(const char *argument, t_set *settings);
static enum e_flag	get_bench_flag(const char *argument, t_set *settings);

int	set_settings(char **input, t_set *settings)
{
	int		i;

	settings->strategy = UNSET;
	settings->bench = false;
	settings->adaptive = false;
	i = 0;
	while (input[i] != NULL)
	{
		if (get_strategy_flag(input[i], settings) == FOUND)
		{
			i++;
			continue ;
		}
		if (get_bench_flag(input[i], settings) == FOUND)
		{
			i++;
			continue ;
		}
		break ;
	}
	if (settings->strategy == UNSET)
		settings->strategy = ADAPTIVE;
	return (i);
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

static enum e_flag	get_bench_flag(const char *argument, t_set *settings)
{
	if (settings->bench == true)
		return (ALREADY_SET);
	else if (strmatch(argument, "--bench") == true)
	{
		settings->bench = true;
		return (FOUND);
	}
	else
		return (NOT_FOUND);
}

static enum e_flag	get_strategy_flag(const char *argument, t_set *settings)
{
	if (settings->strategy != UNSET)
		return (ALREADY_SET);
	else if (strmatch(argument, "--adaptive") == true)
		settings->strategy = ADAPTIVE;
	else if (strmatch(argument, "--simple") == true)
		settings->strategy = SIMPLE;
	else if (strmatch(argument, "--medium") == true)
		settings->strategy = MEDIUM;
	else if (strmatch(argument, "--complex") == true)
		settings->strategy = COMPLEX;
	else
		return (NOT_FOUND);
	return (FOUND);
}
