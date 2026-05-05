/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   print_bench.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/05 18:16:52 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/05 18:22:28 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_bench(float disorder, enum e_strategy strategy, int *stats)
{
	printf("Disorder: %f\n", disorder);
	printf("Strategy: %d\n", strategy);
	printf("Stats coming soon!\n");
	(void)stats;
}
