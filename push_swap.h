/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 19:37:47 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/04/30 16:16:21 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct s_num
{
	int				num;
	struct s_num	*prev;
	struct s_num	*next;
}					t_num;

typedef struct s_stack
{
	t_num			*top;
	t_num			*bottom;
	int				size;
}					t_stack;

void	stack_init(t_stack *stack);

#endif
