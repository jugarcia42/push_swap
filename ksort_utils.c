/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugarcia <jugarcia@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:41:02 by jugarcia          #+#    #+#             */
/*   Updated: 2025/09/05 15:43:07 by jugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = number;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_back(t_stack **stack, t_stack *node_to_add)
{
	t_stack	*last_node;

	if (!*stack)
	{
		*stack = node_to_add;
		return ;
	}
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = node_to_add;
}

int	count_arguments(char **argv)
{
	int		arg_index;
	int		num_index;
	int		total_count;
	char	**numbers_in_arg;

	arg_index = 1;
	total_count = 0;
	while (argv[arg_index])
	{
		num_index = 0;
		numbers_in_arg = ft_split(argv[arg_index], ' ');
		while (numbers_in_arg[num_index])
		{
			total_count++;
			free(numbers_in_arg[num_index]);
			num_index++;
		}
		free(numbers_in_arg);
		arg_index++;
	}
	return (total_count);
}

void	assign_sorted_index(t_stack **stack)
{
	t_stack	*current_node;
	t_stack	*node_to_compare;
	int		index_value;

	current_node = *stack;
	while (current_node)
	{
		index_value = 0;
		node_to_compare = *stack;
		while (node_to_compare)
		{
			if (current_node->value > node_to_compare->value)
				index_value++;
			node_to_compare = node_to_compare->next;
		}
		current_node->index = index_value;
		current_node = current_node->next;
	}
}
