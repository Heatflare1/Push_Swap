/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:40:02 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/13 18:20:21 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	if (stack->b.b_top < 0)
		return ;
	stack->a.a_top++;
	stack->a.a_stack[stack->a.a_top] = stack->b.b_stack[stack->b.b_top];
	stack->b.b_top--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	if (stack->a.a_top < 0)
		return ;
	stack->b.b_top++;
	stack->b.b_stack[stack->b.b_top] = stack->a.a_stack[stack->a.a_top];
	stack->a.a_top--;
	write(1, "pb\n", 3);
}