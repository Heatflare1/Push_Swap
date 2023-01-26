/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:40:02 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/26 15:25:31 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stacks *stack)
{
	if (stack->b.top < 0)
		return ;
	stack->a.top++;
	stack->a.stack[stack->a.top] = stack->b.stack[stack->b.top];
	stack->b.top--;
}

void	pb(t_stacks *stack)
{
	if (stack->a.top < 0)
		return ;
	stack->b.top++;
	stack->b.stack[stack->b.top] = stack->a.stack[stack->a.top];
	stack->a.top--;
}
