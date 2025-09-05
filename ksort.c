/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:40:25 by jugarcia          #+#    #+#             */
/*   Updated: 2025/09/05 15:43:05 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_sqrt(int number)
{
	int	i;

	i = 0;
	while ((i * i) <= number)
		i++;
	return (i - 1);
}

void	sort_in_groups(t_stack **stack_a, t_stack **stack_b, int total_elements)
{
	int	chunk_i;
	int	i;

	chunk_i = (calculate_sqrt(total_elements) * 133) / 100;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk_i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

static int	find_position_of_largest_index(t_stack *stack)
{
	int	largest_index;
	int	position;
	int	i;

	largest_index = stack->index;
	position = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > largest_index)
		{
			largest_index = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

static int	get_stack_i(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sort_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	i;

	while (*stack_b)
	{
		position = find_position_of_largest_index(*stack_b);
		i = get_stack_i(*stack_b);
		if (position <= (i / 2))
		{
			while (position-- > 0)
				rb(stack_b);
		}
		else
		{
			while (position++ < i)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
