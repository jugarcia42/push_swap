/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:41:27 by jugarcia          #+#    #+#             */
/*   Updated: 2025/09/05 16:22:51 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort_strategy(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 2)
		sa(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 4)
		sort_four(stack_a, stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else if (count == 6)
		sort_six(stack_a, stack_b);
	else
	{
		assign_sorted_index(stack_a);
		sort_in_groups(stack_a, stack_b, count);
		sort_back_to_a(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		parse_arg_status;
	int		parse_stack_status;
	int		total_numbers;

	stack_a = NULL;
	stack_b = NULL;
	parse_arg_status = parse_arguments(argc, argv, &stack_a);
	if (parse_arg_status == 1)
		return (free_stack(&stack_a), 1);
	else if (parse_arg_status == -1)
		return (0);
	parse_stack_status = parse_stack(stack_a);
	if (parse_stack_status == 1)
		return (free_stack(&stack_a), 1);
	else if (parse_stack_status == -1)
		return (free_stack(&stack_a), 0);
	total_numbers = count_arguments(argv);
	select_sort_strategy(&stack_a, &stack_b, total_numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
