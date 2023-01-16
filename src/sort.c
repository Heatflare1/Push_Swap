/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:51:18 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/16 17:17:57 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a(t_stacks *stack, int push)
{
	int pivot;
	int old_push;
	
	old_push = push;
	if (swapa_or_not(stack) == 1)
		return ;
	if (is_sorted(stack->a, push) == 1)
		return ;
	pivot = pivot_finder(stack, stack->a, push);
	push = pivot_bpush(stack, push, pivot);
	quicksort_a(stack, old_push - push);
	quicksort_b(stack, push);
}

void	quicksort_b(t_stacks *stack, int push)
{
	int pivot;
	int old_push;
	
	old_push = push;
	if (swapb_or_not(stack) == 1)
		return(push_to_a(stack, push));
	if (is_sortedb(stack->b, push) == 1)
		return (push_to_a(stack, push));
	pivot = pivot_finder(stack, stack->b, push);	
	push = pivot_apush(stack, push, pivot);
	quicksort_a(stack, push);
	quicksort_b(stack, old_push - push);
}