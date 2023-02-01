/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:32:40 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/01 11:12:19 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	valid_digit(char *digit)
{
	int	i;

	i = 0;
	if (digit[0] == '-' && digit[1] != '\0')
		i++;
	while (digit[i])
	{
		if (ft_isdigit(digit[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	sorting(t_stacks *stack, int elements)
{
	int	temp;
	int	index;
	int	sorted;

	sorted = false;
	while (!sorted)
	{
		sorted = true;
		index = 0;
		while (index <= elements - 1)
		{
			if (stack->sorted[index] >= stack->sorted[index + 1])
			{
				if (stack->sorted[index] == stack->sorted[index + 1])
					error_exit(NULL, 0, 4, stack);
				temp = stack->sorted[index];
				stack->sorted[index] = stack->sorted[index + 1];
				stack->sorted[index + 1] = temp;
				sorted = false;
			}
			index++;
		}
	}
}

int	pivot_finder(t_stacks *main, t_stack *stack, int elements)
{
	int	pivot;

	main->sorted = malloc((elements + 1) * sizeof(int));
	if (!main->sorted)
		error_exit(NULL, 0, 3, main);
	ft_memcpy(main->sorted, stack->stack + stack->top - elements, \
	(elements + 1) * sizeof(int));
	sorting(main, elements);
	pivot = main->sorted[elements / 2];
	free(main->sorted);
	return (pivot);
}

void	int_assembly(t_stacks *stack, char *argv[], int argc)
{
	int		numb;
	int		i;
	int		index;

	index = 0;
	i = stack->total - 1;
	while (i >= 0)
	{
		if (!valid_digit(argv[i]) || ft_atoi_overflow(argv[i], &numb) \
		|| ft_strlen(argv[i]) == 0)
		{
			error_exit(argv, argc, 3, stack);
		}
		stack->a.stack[index] = numb;
		i--;
		index++;
	}
	if (argc == 2)
		ft_2dfree(argv);
	stack->a.top = stack->total - 1;
	pivot_finder(stack, &stack->a, stack->a.top);
	stack->b.top = -1;
}
