/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:39:09 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/20 17:30:02 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stacks *stack)
{
	if (stack->a.stack[stack->a.top] > stack->a.stack[stack->a.top - 1]
		&& stack->a.stack[stack->a.top - 1] > stack->a.stack[stack->a.top - 2])
	{
		sa(stack);
		rra(stack);
	}
	else if (stack->a.stack[stack->a.top] > stack->a.stack[stack->a.top - 2]
		&& stack->a.stack[stack->a.top - 1] < stack->a.stack[stack->a.top - 2])
		ra(stack);
	else if (stack->a.stack[stack->a.top] > stack->a.stack[stack->a.top - 1]
		&& stack->a.stack[stack->a.top] < stack->a.stack[stack->a.top - 2])
		sa(stack);
	else if (stack->a.stack[stack->a.top] < stack->a.stack[stack->a.top - 1]
		&& stack->a.stack[stack->a.top] > stack->a.stack[stack->a.top - 2])
		rra(stack);
	else if (stack->a.stack[stack->a.top - 2] > stack->a.stack[stack->a.top]
		&& stack->a.stack[stack->a.top - 1] > stack->a.stack[stack->a.top - 2])
	{
		rra(stack);
		sa(stack);
	}
}

void	sort_three_b(t_stacks *stack)
{
	if (stack->b.stack[stack->b.top] < stack->b.stack[stack->b.top - 1]
		&& stack->b.stack[stack->b.top - 1] < stack->b.stack[stack->b.top - 2])
	{
		sb(stack);
		rrb(stack);
	}
	else if (stack->b.stack[stack->b.top] > stack->b.stack[stack->b.top - 2]
		&& stack->b.stack[stack->b.top - 1] < stack->b.stack[stack->b.top - 2])
	{
		sb(stack);
		rb(stack);
	}
	else if (stack->b.stack[stack->b.top] > stack->b.stack[stack->b.top - 1]
		&& stack->b.stack[stack->b.top] < stack->b.stack[stack->b.top - 2])
		rrb(stack);
	else if (stack->b.stack[stack->b.top] < stack->b.stack[stack->b.top - 1]
		&& stack->b.stack[stack->b.top] > stack->b.stack[stack->b.top - 2])
		sb(stack);
	else if (stack->b.stack[stack->b.top - 2] > stack->b.stack[stack->b.top]
		&& stack->b.stack[stack->b.top - 1] > stack->b.stack[stack->b.top - 2])
		rb(stack);
}

int	swap_sort_a(t_stacks *stack, int push)
{
	if (swapa_or_not(stack, push) == 1)
		return (1);
	if (is_sorted(&stack->a, push) == 1)
		return (1);
	if (stack->a.top > 2)
		return (0);
	sort_three_a(stack);
	return (1);
}

int	swap_sort_b(t_stacks *stack, int push)
{
	if (swapb_or_not(stack, push) == 1)
		return (1);
	if (is_sortedb(&stack->b, push) == 1)
		return (1);
	if (stack->b.top > 2)
		return (0);
	sort_three_b(stack);
	return (1);
}
