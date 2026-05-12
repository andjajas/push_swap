/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ops_put_operation.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/12 14:18:21 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/12 14:51:20 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_put_operation(enum e_operation operation, int *stats)
{
	char	*op_strings[11];

	if (stats != NULL)
	{
		stats[operation]++;
		return ;
	}
	op_strings[SA] = "sa\n";
	op_strings[SB] = "sb\n";
	op_strings[SS] = "ss\n";
	op_strings[PA] = "pa\n";
	op_strings[PB] = "pb\n";
	op_strings[RA] = "ra\n";
	op_strings[RB] = "rb\n";
	op_strings[RR] = "rr\n";
	op_strings[RRA] = "rra\n";
	op_strings[RRB] = "rrb\n";
	op_strings[RRR] = "rrr\n";
	ft_putstr(op_strings[operation]);
}
