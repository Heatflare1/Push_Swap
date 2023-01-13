/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:32:40 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/13 16:59:02 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valid_digit(char *digit, t_stack *stack)
{
	int	i;

	i = 0;
	if (digit[0] == '-')
		i++;
	while (digit[i])
	{
		if (ft_isdigit(digit[i]) == 0)
			error_exit(3, stack);
		i++;
	}
}
void	sorting(t_stack *stack, int index, int end)
{
	int temp;
	int flag;
	
	flag = 1;
	while (index < end - 1)
	{
		if (stack->sorted[index] >= stack->sorted[index + 1])
		{
			if (stack->sorted[index] == stack->sorted[index + 1])
				error_exit(4, stack);
			temp = stack->sorted[index];
			stack->sorted[index] = stack->sorted[index + 1];
			stack->sorted[index + 1] = temp;
			flag = 0;
		}
		index++;
		if (flag == 0)
		{
			index = 0;
			flag = 1;
		}
	}
}

int	pivot_finder(t_stack *stack, int start, int end)
{
	int pivot;

	stack->sorted = malloc((end - start) * sizeof(int));
	if (!stack->sorted)
		error_exit(3, stack);
	ft_memcpy(stack->sorted, stack->a.a_stack + start, (end - start) * sizeof(int));
	sorting(stack, 0, end - start);
	for (pivot = 0; pivot < end; pivot++)
		printf("sort{%d}\n", stack->sorted[pivot]);
	pivot = stack->sorted[(end - start)];
	free(stack->sorted);
	return (pivot);
}

void	int_assembly(t_stack *stack, char *argv[])
{
	long	numb;
	int		i;

	i = stack->total - 1;
	while (i >= 0)
	{
		valid_digit(argv[i], stack);
		numb = ft_latoi(argv[i]);
		if (!(numb <= INT_MAX && numb >= INT_MIN) || ft_strlen(argv[i]) == 0)
			error_exit(3, stack);
		stack->a.a_stack[i] = (int)numb;
		i--;
	}
	stack->a.a_top = stack->total;
	pivot_finder(stack, 0, stack->total);
}
