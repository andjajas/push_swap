/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printfcustom_utils.c                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/07 19:36:23 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/08 15:00:18 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_disorder(float disorder)
{
	(void)disorder;
}

void	ft_put_strategy(t_e_strategy strategy, float disorder)
{
	if (strategy == ADAPTIVE)
	{
		ft_putstr("Adaptive");
		strategy = get_strategy(disorder);
	}
	else if (strategy == SIMPLE)
		ft_putstr("Simple");
	else if (strategy == MEDIUM)
		ft_putstr("Medium");
	else if (strategy == COMPLEX)
		ft_putstr("Complex");
	ft_putstr(" / ");
	if (strategy == SIMPLE)
		ft_putstr("O(n^2)");
	else if (strategy == MEDIUM)
		ft_putstr("O(n sqrt(n))");
	else if (strategy == COMPLEX)
		ft_putstr("O(n log n)");
}

void	ft_put_uint(unsigned int n)
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
