/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   libft_functions.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/01 12:40:07 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/04 21:34:39 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (true);
	else
		return (false);
}

bool	ft_isspace(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (true);
	else
		return (false);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

long long int	ft_atoi(const char *string)
{
	size_t				i;
	long long int		number;
	bool				isnegative;

	i = 0;
	number = 0;
	isnegative = false;
	while (ft_isspace(string[i]) == true)
		i++;
	if (string[i] == '+')
		i++;
	else if (string[i] == '-')
	{
		isnegative = true;
		i++;
	}
	while (ft_isdigit(string[i]) == true)
	{
		number *= 10;
		number += string[i] - '0';
		i++;
	}
	if (isnegative == true)
		return (number * -1);
	return (number);
}
