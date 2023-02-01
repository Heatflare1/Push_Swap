/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:40:20 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/01 11:20:32 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argument_converter(int argc, char *argv[], t_stacks *stack)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack->total = ft_2d_arrlen(argv);
	}
	else
	{
		argv++;
		stack->total = (argc - 1);
	}
	if (!argv)
		error_exit(argv, 1, 1, stack);
	return (argv);
}

void	clean_exit(t_stacks *stack)
{
	free(stack->a.stack);
	free(stack->b.stack);
}

void	error_exit(char *argv[], int argc, int error_code, t_stacks *stack)
{
	if (error_code > 4)
		free(stack->sorted);
	if (argc == 2)
		ft_2d_arrlen(argv);
	if (error_code > 2)
		free(stack->b.stack);
	if (error_code > 1)
		free(stack->a.stack);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_stacks	stack;

	if (argc < 2)
		return (EXIT_SUCCESS);
	argv = argument_converter(argc, argv, &stack);
	stack.a.stack = malloc(stack.total * sizeof(int));
	if (!stack.a.stack)
		error_exit(argv, argc, 1, &stack);
	stack.b.stack = malloc(stack.total * sizeof(int));
	if (!stack.b.stack)
		error_exit(argv, argc, 2, &stack);
	int_assembly(&stack, argv, argc);
	if (!is_sorted(&stack.a, stack.total))
		quicksort_a(&stack, stack.total);
	clean_exit(&stack);
	return (EXIT_SUCCESS);
}
