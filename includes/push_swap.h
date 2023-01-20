/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:25 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/20 18:20:16 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int	*stack;
	int top;
}	t_stack;

typedef struct s_stacks
{
	t_stack a;
	t_stack b;
	int total;
	int *sorted;
	int sign;
}	t_stacks;

void	int_assembly(t_stacks *stack, char *argv[]);
int		pivot_finder(t_stacks *main, t_stack *stack, int end);

int		is_sorted(t_stack *stack, int end);
int		is_sortedb(t_stack *stack, int end);
int		swap_sort_a(t_stacks *stack, int push);
int		swap_sort_b(t_stacks *stack, int push);
int		swapa_or_not(t_stacks *stack, int push);
int		swapb_or_not(t_stacks *stack, int push);
void	error_exit(int error_code, t_stacks *stack);

void	quicksort_a(t_stacks *stack, int push);
void	quicksort_b(t_stacks *stack, int push);

void	ra(t_stacks *stack);
void	rra(t_stacks *stack);
void	rb(t_stacks *stack);
void	rrb(t_stacks *stack);

void	pa(t_stacks *stack);
void	pb(t_stacks *stack);
int		pivot_bpush(t_stacks *stack, int push, int pivot);
int		pivot_apush(t_stacks *stack, int push, int pivot);
void	push_to_a(t_stacks *stack, int push);

void	sa(t_stacks *stack);
void	sb(t_stacks *stack);

#endif
