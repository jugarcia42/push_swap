/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:25:08 by jugarcia          #+#    #+#             */
/*   Updated: 2025/08/27 17:25:10 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicates(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = *stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (checker->value == current->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

static int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	parse_stack(t_stack *stack_a)
{
	if (has_duplicates(&stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (is_sorted(&stack_a))
		return (-1);
	return (0);
}
