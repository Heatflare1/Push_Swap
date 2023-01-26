/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:27:23 by jisse             #+#    #+#             */
/*   Updated: 2023/01/26 15:57:47 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	execute(t_stacks *stack, char *operation)
{
	if (ft_strncmp(operation, "pa\n", 3) == 0 && ft_strlen(operation) == 3)
		pa(stack);
	else if (ft_strncmp(operation, "pb\n", 3) == 0 && ft_strlen(operation) == 3)
		pb(stack);
	else if (ft_strncmp(operation, "ra\n", 3) == 0 && ft_strlen(operation) == 3)
		ra(stack);
	else if (ft_strncmp(operation, "rb\n", 3) == 0 && ft_strlen(operation) == 3)
		rb(stack);
	else if (ft_strncmp(operation, "rr\n", 3) == 0 && ft_strlen(operation) == 3)
		rr(stack);
	else if (ft_strncmp(operation, "sa\n", 3) == 0 && ft_strlen(operation) == 3)
		sa(stack);
	else if (ft_strncmp(operation, "sb\n", 3) == 0 && ft_strlen(operation) == 3)
		sb(stack);
	else if (ft_strncmp(operation, "ss\n", 3) == 0 && ft_strlen(operation) == 3)
		ss(stack);
	else if (ft_strncmp(operation, "rra\n", 4) == 0 && ft_strlen(operation) == 4)
		rra(stack);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0 && ft_strlen(operation) == 4)
		rrb(stack);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0 && ft_strlen(operation) == 4)
		rrr(stack);
}

void	reading(t_stacks *stack)
{
	char *operation;

	operation = get_next_line(STDIN_FILENO);
	while (operation)
	{
		execute(stack, operation);
		free(operation);
		operation = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(&stack->a, stack->total) && stack->b.top == -1)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}