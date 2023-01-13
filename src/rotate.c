/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:19:45 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/13 18:37:42 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->a.a_top < 1)
		return ;
	temp1 = stack->a.a_stack[stack->a.a_top];
	temp2 = stack->a.a_stack[0];
	i = 0;
	while (i <= stack->a.a_top)
	{
		stack->a.a_stack[i] = temp1;
		temp1 = temp2;
		if ((i + 1) <= stack->a.a_top)
			temp2 = stack->a.a_stack[i + 1];
		i++;
	}
	write(1, "ra\n", 3);
}

void	rra(t_stack *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->a.a_top < 1)
		return ;
	temp1 = stack->a.a_stack[0];
	temp2 = stack->a.a_stack[stack->a.a_top];
	i = stack->a.a_top;
	while (i >= 0)
	{
		stack->a.a_stack[i] = temp1;
		temp1 = temp2;
		if ((i - 1) >= 0)
			temp2 = stack->a.a_stack[i - 1];
		i--;
	}
	write(1, "rra\n", 4);
}

void	rb(t_stack *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->b.b_top < 1)
		return ;
	temp1 = stack->b.b_stack[stack->b.b_top];
	temp2 = stack->b.b_stack[0];
	i = 0;
	while (i <= stack->b.b_top)
	{
		stack->b.b_stack[i] = temp1;
		temp1 = temp2;
		if ((i + 1) <= stack->b.b_top)
			temp2 = stack->b.b_stack[i + 1];
		i++;
	}
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->b.b_top < 1)
		return ;
	temp1 = stack->b.b_stack[0];
	temp2 = stack->b.b_stack[stack->b.b_top];
	i = stack->b.b_top;
	while (i >= 0)
	{
		stack->b.b_stack[i] = temp1;
		temp1 = temp2;
		if ((i - 1) >= 0)
			temp2 = stack->b.b_stack[i - 1];
		i--;
	}
	write(1, "rrb\n", 4);
}