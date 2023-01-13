/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:09:36 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/13 18:41:55 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int i;
	int temp;
	
	if (stack->a.a_top < 1)
		return ;
	temp = stack->a.a_stack[stack->a.a_top];
	stack->a.a_stack[stack->a.a_top] = stack->a.a_stack[stack->a.a_top - 1];
	stack->a.a_stack[stack->a.a_top - 1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int temp;
	
	if (stack->b.b_top < 1)
		return ;
	temp = stack->b.b_stack[stack->b.b_top];
	stack->b.b_stack[stack->b.b_top] = stack->b.b_stack[stack->b.b_top - 1];
	stack->b.b_stack[stack->b.b_top - 1] = temp;
	write(1, "sb\n", 3);	
}
