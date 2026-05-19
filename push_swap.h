/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 19:37:47 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/19 15:34:41 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

// this one exists SOLELY for the use of SIZE_MAX in ft_calloc.
# include <stdint.h>

enum	e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef enum e_did_succeed
{
	SUCCES = true,
	FAILED = false
}	t_did_succeed;

typedef enum e_strategy
{
	UNSET = -1,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_e_strategy;

typedef struct s_settings
{
	t_e_strategy	strategy;
	bool			bench;
}	t_set;

typedef struct s_num
{
	long long		num;
	unsigned int	rank;
	struct s_num	*prev;
	struct s_num	*next;
}	t_num;

typedef struct s_stack
{
	t_num			*top;
	int				size;
}	t_stack;

// used in main
bool			is_valid_input(char **argv);
int				set_settings(char **argv, t_set *settings);
t_did_succeed	convert_to_lst(char **argv, t_stack *stack);
void			push_swap(t_stack *stack_a, t_stack *stack_b, t_set settings);
char			**ft_supersplit(const char **input, bool (*check)(int));
void			free_array(char **array);

// used in push_swap
void			solve_simple(t_stack *stack_a, t_stack *stack_b, int *stats);
void			solve_medium(t_stack *stack_a, t_stack *stack_b, int *stats);
void			solve_complex(t_stack *stack_a, t_stack *stack_b, int *stats);
void			print_bench(float disorder, t_e_strategy strategy, int *stats);
void			ft_printfcustom(const char *string, ...);

// operation functions
void			pa(t_stack *stack_a, t_stack *stack_b, int *stats);
void			pb(t_stack *stack_b, t_stack *stack_a, int *stats);
void			sa(t_stack *stack, int *stats);
void			sb(t_stack *stack, int *stats);
void			ss(t_stack *stack_a, t_stack *stack_b, int *stats);
void			ra(t_stack *stack_a, int *stats);
void			rb(t_stack *stack_b, int *stats);
void			rr(t_stack *stack_a, t_stack *stack_b, int *stats);
void			rra(t_stack *stack_a, int *stats);
void			rrb(t_stack *stack_b, int *stats);
void			rrr(t_stack *stack_a, t_stack *stack_b, int *stats);
void			ops_put_operation(enum e_operation operation, int *stats);

// random function used in push_swap and ft_printfcustom_utils
t_e_strategy	get_strategy(float disorder);

// stack (linked-list) functions
t_num			*new_node(long long num);
void			stack_add_back(t_stack *stack, t_num *new);
void			clear_stack(t_stack *stack);

// libft-like functions
bool			ft_isdigit(int c);
bool			ft_isspace(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr(const char *s);
void			ft_putstr_err(const char *s);
void			ft_bzero(void *memory, size_t n);
long long		ft_atoi(const char *string);

// ft_printfcustom only functions
void			ft_put_strategy(t_e_strategy strategy, float disorder);
void			ft_put_disorder(float disorder);
void			ft_put_uint(unsigned int n);

#endif
