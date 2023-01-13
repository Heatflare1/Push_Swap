/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:51:18 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/13 18:42:10 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_stack *stack)
{
	int i;
	
	pb(stack);
	pb(stack);
	pb(stack);
	pb(stack);
	pb(stack);
	pb(stack);
	for (i=0; i < stack->total; i++)
	{
		if (i <= stack->a.a_top)
			printf("a-old[%d] | ", stack->a.a_stack[i]);
		if (i <= stack->b.b_top)
			printf("b-old[%d]\n", stack->b.b_stack[i]);
		else 
			printf("\n");
	}
	rb(stack);
	sb(stack);
	write(1, "\n", 1);
	for (i=0; i <= stack->total; i++)
	{
		if (i <= stack->a.a_top)
			printf("a-new[%d]\n", stack->a.a_stack[i]);
		if (i <= stack->b.b_top)
			printf("b-new[%d]\n", stack->b.b_stack[i]);
	}
}