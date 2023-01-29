/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:19:45 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/29 15:18:30 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stacks *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->a.top < 1)
		return ;
	temp1 = stack->a.stack[stack->a.top];
	temp2 = stack->a.stack[0];
	i = 0;
	while (i <= stack->a.top)
	{
		stack->a.stack[i] = temp1;
		temp1 = temp2;
		if ((i + 1) <= stack->a.top)
			temp2 = stack->a.stack[i + 1];
		i++;
	}
}

void	rra(t_stacks *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->a.top < 1)
		return ;
	temp1 = stack->a.stack[0];
	temp2 = stack->a.stack[stack->a.top];
	i = stack->a.top;
	while (i >= 0)
	{
		stack->a.stack[i] = temp1;
		temp1 = temp2;
		if ((i - 1) >= 0)
			temp2 = stack->a.stack[i - 1];
		i--;
	}
}

void	rb(t_stacks *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->b.top < 1)
		return ;
	temp1 = stack->b.stack[stack->b.top];
	temp2 = stack->b.stack[0];
	i = 0;
	while (i <= stack->b.top)
	{
		stack->b.stack[i] = temp1;
		temp1 = temp2;
		if ((i + 1) <= stack->b.top)
			temp2 = stack->b.stack[i + 1];
		i++;
	}
}

void	rrb(t_stacks *stack)
{
	int	i;
	int	temp1;
	int	temp2;

	if (stack->b.top < 1)
		return ;
	temp1 = stack->b.stack[0];
	temp2 = stack->b.stack[stack->b.top];
	i = stack->b.top;
	while (i >= 0)
	{
		stack->b.stack[i] = temp1;
		temp1 = temp2;
		if ((i - 1) >= 0)
			temp2 = stack->b.stack[i - 1];
		i--;
	}
}
