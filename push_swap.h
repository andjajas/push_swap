/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-kop <tvan-kop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 19:37:47 by tvan-kop      #+#    #+#                 */
/*   Updated: 2026/05/02 18:34:09 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

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

enum e_strategy
{
	ADAPTIVE;
	SIMPLE;
	MEDIUM;
	COMPLEX
};

enum e_operation
{
	SA;
	SB;
	SS;
	PA;
	PB;
	RA;
	RB;
	RR;
	RRA;
	RRB;
	RRR
};

bool	ft_isdigit(int c);
bool	ft_isspace(int c);
bool	ft_isvalidnumber(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
void	stack_init(t_stack *stack);
t_num	*new_node(int num);
void	stack_add_back(t_stack *stack, t_num *new);
void	clear_stack(t_stack *stack);


#endif
