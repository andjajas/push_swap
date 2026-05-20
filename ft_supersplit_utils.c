/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_supersplit_utils.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/20 18:54:40 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/20 20:15:45 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_splits(const char *s, bool (*check)(int));

size_t	count_supersplits(const char **array, bool (*check)(int))
{
	size_t	count;

	count = 0;
	while (*array != NULL)
	{
		count += count_splits(*array, check);
		array++;
	}
	return (count);
}

int	find_index_func(const char *string, bool (*check)(int))
{
	int	i;

	i = 0;
	while (string[i] != '\0' && check(string[i]) == false)
		i++;
	return (i);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static size_t	count_splits(const char *s, bool (*check)(int))
{
	size_t	count;
	size_t	i;

	while (check(*s) == true)
		s++;
	count = 0;
	i = 0;
	while (true)
	{
		s += find_index_func(s, check);
		count++;
		while (check(*s) == true)
			s++;
		if (s[i] == '\0')
			return (count);
	}
}
