/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:25 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/13 17:57:44 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_a
{
	int	*a_stack;
	int a_top;
}	t_stack_a;

typedef struct s_stack_b
{
	int	*b_stack;
	int b_top;
}	t_stack_b;

typedef struct s_stack
{
	t_stack_a a;
	t_stack_b b;
	int total;
	int *sorted;
}	t_stack;

void	int_assembly(t_stack *stack, char *argv[]);
void	test(t_stack *stack);

void	error_exit(int error_code, t_stack *stack);

void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	rb(t_stack *stack);
void	rrb(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	sa(t_stack *stack);
void	sb(t_stack *stack);

#endif
