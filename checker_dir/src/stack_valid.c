/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:32:40 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/26 15:20:11 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	valid_digit(char *digit, t_stacks *stack)
{
	int	i;

	i = 0;
	if (digit[0] == '-' && digit[1] != '\0')
		i++;
	while (digit[i])
	{
		if (ft_isdigit(digit[i]) == 0)
			error_exit(3, stack);
		i++;
	}
}

void	sorting(t_stacks *stack, int end)
{
	int	temp;
	int	index;
	int	sorted;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
		index = 0;
		while (index < end - 1)
		{
			if (stack->sorted[index] >= stack->sorted[index + 1])
			{
				if (stack->sorted[index] == stack->sorted[index + 1])
					error_exit(4, stack);
				temp = stack->sorted[index];
				stack->sorted[index] = stack->sorted[index + 1];
				stack->sorted[index + 1] = temp;
				sorted = false;
			}
			index++;
		}
	}
}

int	pivot_finder(t_stacks *main, t_stack *stack, int end)
{
	int	pivot;

	main->sorted = malloc(end * sizeof(int));
	if (!main->sorted)
		error_exit(3, main);
	ft_memcpy(main->sorted, stack->stack + ((stack->top + 1) - end), end * 4);
	sorting(main, end);
	pivot = main->sorted[end / 2];
	free(main->sorted);
	return (pivot);
}

void	int_assembly(t_stacks *stack, char *argv[])
{
	int		numb;
	int		i;
	int		index;

	index = 0;
	i = stack->total - 1;
	while (i >= 0)
	{
		valid_digit(argv[i], stack);
		if (ft_atoi_overflow(argv[i], &numb) || ft_strlen(argv[i]) == 0)
			error_exit(3, stack);
		stack->a.stack[index] = numb;
		i--;
		index++;
	}
	stack->a.top = stack->total - 1;
	pivot_finder(stack, &stack->a, stack->a.top);
	stack->b.top = -1;
}
