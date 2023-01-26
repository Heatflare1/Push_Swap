/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:09:36 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/26 15:48:18 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stacks *stack)
{
	int	temp;

	if (stack->a.top < 1)
		return ;
	temp = stack->a.stack[stack->a.top];
	stack->a.stack[stack->a.top] = stack->a.stack[stack->a.top - 1];
	stack->a.stack[stack->a.top - 1] = temp;
}

void	sb(t_stacks *stack)
{
	int	temp;

	if (stack->b.top < 1)
		return ;
	temp = stack->b.stack[stack->b.top];
	stack->b.stack[stack->b.top] = stack->b.stack[stack->b.top - 1];
	stack->b.stack[stack->b.top - 1] = temp;
}

void	ss(t_stacks *stack)
{
	sa(stack);
	sb(stack);
}
