/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf_bench.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/07 19:36:23 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/22 14:02:03 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(const char *string, char c);
static void	print_variable(char identifier, va_list args);

void	ft_printf_bench(const char *string, ...)
{
	va_list	args;
	int		next_percent;

	va_start(args, string);
	while (true)
	{
		next_percent = find_index(string, '%');
		write(STDERR_FILENO, string, next_percent);
		string += next_percent;
		if (*string == '\0')
			break ;
		string++;
		print_variable(*string, args);
		string++;
	}
	va_end(args);
}

static int	find_index(const char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && string[i] != c)
		i++;
	return (i);
}

static void	print_variable(char identifier, va_list args)
{
	if (identifier == 's')
		ft_put_strategy(va_arg(args, t_set));
	else if (identifier == 'd')
		ft_put_disorder(va_arg(args, double));
	else if (identifier == 'u')
		ft_put_uint(va_arg(args, unsigned int));
	else
		ft_putstr_err(
			"\n An error occured. ft_printf_bench was used wrong.\n");
}
