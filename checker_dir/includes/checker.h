/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:25 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/29 15:22:03 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int	*stack;
	int	top;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
	int		total;
	int		*sorted;
	int		sign;
}	t_stacks;

void	int_assembly(t_stacks *stack, char *argv[]);
void	reading(t_stacks *stack);
int		pivot_finder(t_stacks *main, t_stack *stack, int end);

void	error_exit(int error_code, t_stacks *stack);
int		is_sorted(t_stack *stack, int push);

void	ra(t_stacks *stack);
void	rra(t_stacks *stack);
void	rb(t_stacks *stack);
void	rrb(t_stacks *stack);

void	pa(t_stacks *stack);
void	pb(t_stacks *stack);

void	sa(t_stacks *stack);
void	sb(t_stacks *stack);

#endif
