/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:47 by jisse             #+#    #+#             */
/*   Updated: 2023/01/29 15:19:35 by jmeruma          ###   ########.fr       */
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
