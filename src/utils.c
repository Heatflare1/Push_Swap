/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:47 by jisse             #+#    #+#             */
/*   Updated: 2023/01/16 17:25:04 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack, int end)
{
	int	i;
	
	end = stack->top - end;
	i = stack->top;
	while (i > end)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	is_sortedb(t_stack *stack, int end)
{
	int i;
	
	end = stack->top - end;
	i = stack->top;
	while (i > end)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	swapa_or_not(t_stacks *stack)
{
	if (stack->a->top == 1 && stack->a->stack[stack->a->top] > stack->a->stack[stack->a->top - 1])
	{
		sa(stack);
		return (1);
	}
	return (0);
}
int	swapb_or_not(t_stacks *stack)
{
	if (stack->b->top == 1 && stack->b->stack[stack->b->top] < stack->b->stack[stack->b->top - 1])
	{
		sb(stack);
		return (1);
	}
	return (0);
}

void	push_to_a(t_stacks *stack, int push)
{
	int	i;

	i = 0;
	while (i < push)
	{
		pa(stack);
		i++;
	}
	
}