/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 19:37:47 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/04 18:42:11 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

enum				e_strategy
{
	UNSET = -1,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
};

struct s_settings
{
	enum e_strategy	strategy;
	bool			bench;
};

typedef struct s_num
{
	int				num;
	struct s_num	*prev;
	struct s_num	*next;
}					t_num;

typedef struct s_stack
{
	t_num			*top;
	int				size;
}					t_stack;

typedef struct s_stats
{
	int				sa_count;
	int				sb_count;
	int				ss_count;
	int				pa_count;
	int				pb_count;
	int				ra_count;
	int				rb_count;
	int				rr_count;
	int				rra_count;
	int				rrb_count;
	int				rrr_count;
	int				total_operation_count;
}					t_stats;

// enum				e_operation
// {
// 	SA,
// 	SB,
// 	SS,
// 	PA,
// 	PB,
// 	RA,
// 	RB,
// 	RR,
// 	RRA,
// 	RRB,
// 	RRR
// };

bool				ft_isdigit(int c);
bool				ft_isspace(int c);
bool				is_valid_input(char **argv);
size_t				ft_strlen(const char *s);
void				ft_putstr(const char *s);
void				stack_init(t_stack *stack);
t_num				*new_node(int num);
void				stack_add_back(t_stack *stack, t_num *new);
void				clear_stack(t_stack *stack);
t_num				*stack_pop_top(t_stack *stack);
void				stack_add_front(t_stack *stack, t_num *new);
void				pa(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void				pb(t_stack *stack_b, t_stack *stack_a, t_stats *stats);
void				sa(t_stack *stack, t_stats *stats);
void				sb(t_stack *stack, t_stats *stats);
struct s_settings	set_settings(int argc, char **argv, int *i);

#endif
