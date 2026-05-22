/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   convert_to_lst.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: tvan-kop <tvan-kop@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/05/04 21:08:35 by tvan-kop     #+#    #+#                  */
/*   Updated: 2026/05/22 14:40:55 by tvan-kop     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_is_valid_number(const char *s);
static bool	check_duplicate(t_stack *stack, int number);
static bool	out_of_bounds(long long number);

t_did_succeed	convert_to_lst(char **input, t_stack *stack)
{
	t_num			*node;

	while (*input != NULL)
	{
		node = new_node(ft_atoi(*input));
		if (node == NULL
			|| ft_is_valid_number(*input) == false
			|| out_of_bounds(node->num) == true
			|| check_duplicate(stack, node->num) == true)
		{
			free(node);
			clear_stack(stack);
			return (FAILED);
		}
		stack_add_back(stack, node);
		input++;
	}
	return (SUCCES);
}

static bool	ft_is_valid_number(const char *s)
{
	while (ft_isspace(*s) == true)
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (ft_strlen(s) > 10)
		return (false);
	if (ft_isdigit(*s) == false)
		return (false);
	s++;
	while (ft_isdigit(*s) == true)
		s++;
	if (*s == '\0')
		return (true);
	else
		return (false);
}

static bool	out_of_bounds(long long number)
{
	if (INT_MIN <= number && number <= INT_MAX)
		return (false);
	else
		return (true);
}

static bool	check_duplicate(t_stack *stack, int number)
{
	t_num	*current_node;
	int		i;

	current_node = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (current_node->num == number)
			return (true);
		current_node = current_node->next;
		i++;
	}
	return (false);
}
