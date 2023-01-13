/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:40:20 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/13 17:57:35 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argument_converter(int argc, char *argv[], t_stack *stack)
{
	int	i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		error_exit(1, stack);
	else 
		argv++;
	while (argv[i])
		i++;
	stack->total = i;
	return (argv);
}

void	error_exit(int error_code, t_stack *stack)
{
	if (error_code > 4)
		free(stack->sorted);
	if (error_code > 2)
		free(stack->b.b_stack);
	if (error_code > 1)
		free(stack->a.a_stack);
	if (error_code > 0)
		free(stack);
	ft_printf("error_code = %d ", error_code);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int i;
	t_stack	*stack;

	i = 0;
	if (argc < 2)
		return (EXIT_SUCCESS);
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		error_exit(0, stack);
	argv = argument_converter(argc, argv, stack);
	stack->a.a_stack = malloc(stack->total * sizeof(int));
	if (!stack->a.a_stack)
		error_exit(1, stack);
	stack->b.b_stack = malloc(stack->total * sizeof(int));
	if (!stack->b.b_stack)
		error_exit(2, stack);
	int_assembly(stack, argv);
	test(stack);
}
