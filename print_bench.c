/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   print_bench.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/05 18:16:52 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/22 14:32:48 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	stats_total(int *stats);

void	print_bench(float disorder, t_set settings, int *stats)
{
	ft_printf_bench("[bench] disorder: %d\n", disorder);
	ft_printf_bench("[bench] strategy: %s\n", settings);
	ft_printf_bench("[bench] total_ops: %u\n", stats_total(stats));
	ft_printf_bench("[bench] sa: %u sb: %u ss: %u pa: %u pb: %u\n",
		stats[SA], stats[SB], stats[SS], stats[PA], stats[PB]);
	ft_printf_bench("[bench] ra: %u rb: %u rr: %u rra: %u rrb: %u rrr: %u\n",
		stats[RA], stats[RB], stats[RR], stats[RRA], stats[RRB], stats[RRR]);
}

static unsigned int	stats_total(int *stats)
{
	unsigned int	total;
	int				i;

	total = 0;
	i = 0;
	while (i < 11)
	{
		total += (unsigned int) stats[i];
		i++;
	}
	return (total);
}
