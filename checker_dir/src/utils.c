/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:47 by jisse             #+#    #+#             */
/*   Updated: 2023/01/26 15:23:35 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_stack *stack, int push)
{
	int	i;

	if (push <= 1)
		return (1);
	i = 1;
	while (i < push)
	{
		if (stack->stack[stack->top - i] < stack->stack[stack->top - i + 1])
			return (0);	
		i++;
	}
	return (1);
}
