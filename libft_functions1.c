/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   libft_functions.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/01 12:40:07 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/22 12:50:35 by tvan-kop     ########   odam.nl          */
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
	write(STDOUT_FILENO, s, ft_strlen(s));
}

void	ft_putstr_err(const char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
}
