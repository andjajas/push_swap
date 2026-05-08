/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printfcustom_utils.c                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/07 19:36:23 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/08 18:28:45 by tvan-kop     ########   odam.nl          */
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
		ft_putstr_fd("Adaptive", STDOUT_FILENO);
		strategy = get_strategy(disorder);
	}
	else if (strategy == SIMPLE)
		ft_putstr_fd("Simple", STDOUT_FILENO);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium", STDOUT_FILENO);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Complex", STDOUT_FILENO);
	ft_putstr_fd(" / ", STDOUT_FILENO);
	if (strategy == SIMPLE)
		ft_putstr_fd("O(n^2", STDOUT_FILENO);
	else if (strategy == MEDIUM)
		ft_putstr_fd("O(n sqrt(n)", STDOUT_FILENO);
	else if (strategy == COMPLEX)
		ft_putstr_fd("O(n log n", STDOUT_FILENO);
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
	ft_putstr_fd(number, STDOUT_FILENO);
}
