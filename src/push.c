/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:40:02 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/18 20:27:14 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stack)
{
	if (stack->b.top < 0)
		return ;
	stack->a.top++;
	stack->a.stack[stack->a.top] = stack->b.stack[stack->b.top];
	stack->b.top--;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stack)
{
	if (stack->a.top < 0)
		return ;
	stack->b.top++;
	stack->b.stack[stack->b.top] = stack->a.stack[stack->a.top];
	stack->a.top--;
	write(1, "pb\n", 3);
}

int	pivot_bpush(t_stacks *stack, int push, int pivot)
{
	int i;
	int amount_p;

	i = 0;
	amount_p = 0;
	while (i < push)
	{
		if (stack->a.stack[stack->a.top] < pivot)
		{
			pb(stack);
			amount_p++;
		}
		else
			ra(stack);	
		i++;
	}
	return (amount_p);
}

int	pivot_apush(t_stacks *stack, int push, int pivot)
{
	int i;
	int amount_p;

	i = 0;
	amount_p = 0;
	while (i < push)
	{
		if (stack->b.stack[stack->b.top] > pivot)
		{
			pa(stack);
			amount_p++;
		}
		else
			rb(stack);
		i++;
	}
	return (amount_p);
}