/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf_bench_utils.c                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/07 19:36:23 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/22 11:53:40 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_strategy(t_strategy strategy, float disorder)
{
	if (strategy == ADAPTIVE)
	{
		ft_putstr_err("Adaptive");
		strategy = get_strategy(disorder);
	}
	else if (strategy == SIMPLE)
		ft_putstr_err("Simple");
	else if (strategy == MEDIUM)
		ft_putstr_err("Medium");
	else if (strategy == COMPLEX)
		ft_putstr_err("Complex");
	ft_putstr_err(" / ");
	if (strategy == SIMPLE)
		ft_putstr_err("O(n^2)");
	else if (strategy == MEDIUM)
		ft_putstr_err("O(n sqrt(n))");
	else if (strategy == COMPLEX)
		ft_putstr_err("O(n log n)");
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
	ft_putstr_err(number);
}

void	ft_put_disorder(float disorder)
{
	disorder += 0.00005;
	ft_putstr_err("%");
	disorder *= 100;
	ft_put_uint((unsigned int) disorder);
	disorder -= (unsigned int) disorder;
	disorder *= 100;
	ft_putstr_err(".");
	if (disorder < 10 || disorder == 0)
		ft_putstr_err("0");
	ft_put_uint((unsigned int) disorder);
}
