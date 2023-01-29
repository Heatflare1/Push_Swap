/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:40:20 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/27 16:47:50 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argument_converter(int argc, char *argv[], t_stacks *stack)
{
	int	i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		error_exit(1, stack);
	if (argc != 2)
	{
		argv++;
		stack->total = (argc - 1);
	}
	else
	{
		while (argv[i] != '\0')
			i++;
		stack->total = i;
	}
	return (argv);
}

void	error_exit(int error_code, t_stacks *stack)
{
	if (error_code > 4)
		free(stack->sorted);
	if (error_code > 2)
		free(stack->b.stack);
	if (error_code > 1)
		free(stack->a.stack);
	if (error_code > 0)
		free(stack);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stack;

	if (argc < 2)
		return (EXIT_SUCCESS);
	stack = ft_calloc(1, sizeof(t_stacks));
	if (!stack)
		error_exit(0, stack);
	argv = argument_converter(argc, argv, stack);
	stack->a.stack = malloc(stack->total * sizeof(int));
	if (!stack->a.stack)
		error_exit(1, stack);
	stack->b.stack = malloc(stack->total * sizeof(int));
	if (!stack->b.stack)
		error_exit(2, stack);
	int_assembly(stack, argv);
	if (is_sorted(&stack->a, stack->total) == 1)
		return (EXIT_SUCCESS);
	quicksort_a(stack, stack->total);
	return (EXIT_SUCCESS);
}
