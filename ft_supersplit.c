/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_supersplit.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/11 15:32:21 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/12 21:02:28 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_split(char **dest, const char *s, char c);
static size_t	count_supersplits(const char **array, char c);
static size_t	count_splits(const char *s, char c);
static char		*ft_substr(const char *s, size_t len);
static size_t	min(size_t a, size_t b);
static void		*ft_calloc(size_t nmemb, size_t size);

char	**ft_supersplit(const char **input, char c)
{
	size_t	split_amount;
	size_t	splits;
	size_t	i;
	char	**result;

	split_amount = count_supersplits(input, c);
	result = ft_calloc(split_amount + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < split_amount)
	{
		splits = ft_split(result + i, *input, c);
		if (splits == 0)
		{
			free_array(result);
			return (NULL);
		}
		i += splits;
		input++;
	}
	if (i > split_amount)
		ft_putstr_err("PROBLEM IN FT_SUPERSPLIT\n");
	return (result);
}

static size_t	ft_split(char **dest, const char *s, char c)
{
	size_t	i;
	size_t	next_split;

	i = 0;
	while (*s == c)
		s++;
	while (true)
	{
		next_split = find_index(s, c);
		dest[i] = ft_substr(s, next_split);
		if (dest[i] == NULL)
			return (0);
		s += next_split;
		i++;
		while (*s == c)
			s++;
		if (*s != '\0')
			return (i);
	}
}

static size_t	count_supersplits(const char **array, char c)
{
	size_t	count;

	count = 0;
	while (*array != NULL)
	{
		count += count_splits(*array, c);
		array++;
	}
	return (count);
}

static size_t	count_splits(const char *s, char c)
{
	size_t	count;
	size_t	i;

	while (*s == c)
		s++;
	count = 0;
	i = 0;
	while (true)
	{
		s += find_index(s, c);
		count++;
		while (*s == c)
			s++;
		if (s[i] != '\0')
			return (count);
	}
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

static char	*ft_substr(char const *s, size_t len)
{
	char	*substring;
	size_t	substring_length;
	size_t	i;

	substring_length = min(ft_strlen(s), len);
	substring = malloc(sizeof(char) * (substring_length + 1));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < substring_length)
	{
		substring[i] = s[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;	
	void	*return_pointer;

	if (size != 0 && (SIZE_MAX / size) < nmemb)
		return (NULL);
	total_size = nmemb * size;
	return_pointer = malloc(total_size);
	if (return_pointer == NULL)
		return (NULL);
	ft_bzero(return_pointer, total_size);
	return (return_pointer);
}
