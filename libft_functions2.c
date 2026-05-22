/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   libft_functions2.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/22 12:50:47 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/22 12:50:58 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *memory, size_t n)
{
	unsigned char	*byte;
	size_t			i;

	byte = (unsigned char *) memory;
	i = 0;
	while (i < n)
	{
		byte[i] = 0;
		i++;
	}
}

long long	ft_atoi(const char *string)
{
	size_t		i;
	long long	number;
	bool		isnegative;

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
