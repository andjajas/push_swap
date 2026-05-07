/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printfcustom.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/07 19:36:23 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/07 22:14:14 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_put_disorder(float disorder);
static void			ft_put_strategy(t_e_strategy strategy);
static void			ft_put_uint(unsigned int n);
static int			find(const char *string, char c);

void	ft_printfcustom(const char *string, ...)
{
	va_list	args;
	int		next_percent;

	va_start(args, string);
	while (true)
	{
		next_percent = find(string, '%');
		write(1, string, next_percent);
		string += next_percent;
		if (*string == '\0')
			break ;
		string++;
		if (*string == 's')
			ft_put_strategy(va_arg(args, int));
		else if (*string == 'd')
			ft_put_disorder(va_arg(args, t_e_strategy));
		else if (*string == 'u')
			ft_put_uint(va_arg(args, unsigned int));
		string++;
	}
	va_end(args);
}

static void	ft_put_disorder(float disorder)
{
	(void)disorder;
}

static void	ft_put_strategy(t_e_strategy strategy)
{
	if (strategy == ADAPTIVE)
		ft_putstr("Adaptive");
	else if (strategy == SIMPLE)
		ft_putstr("Simple");
	else if (strategy == MEDIUM)
		ft_putstr("Medium");
	else if (strategy == COMPLEX)
		ft_putstr("Complex");
}

static void	ft_put_uint(unsigned int n)
{
	unsigned int	int_len;
	unsigned int	n_copy;
	char			number[11];

	n_copy = n;
	int_len = 1;
	while (n_copy >= 10)
	{
		n_copy /= 10;
		int_len++;
	}
	number[int_len] = '\0';
	while (int_len > 0)
	{
		int_len--;
		number[int_len] = '0' + n % 10;
		n /= 10;
	}
	ft_putstr(number);
}

static int	find(const char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && string[i] != c)
		i++;
	return (i);
}
