#include "push_swap.h"

/**
 * Ordena una pila de 3 elementos.
 */
void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first > third)
	{
		ra(stack_a);
		if (second > third)
			sa(stack_a);
	}
	else if (first > second && first < third)
		sa(stack_a);
	else if (first < second && second > third)
	{
		rra(stack_a);
		if (first < third)
			sa(stack_a);
	}
}

/**
 * Busca la posición del número más pequeño en la pila.
 */
static int	get_position_of_smallest(t_stack *stack)
{
	int	smallest;
	int	position;
	int	index;

	smallest = stack->value;
	position = 0;
	index = 0;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			position = index;
		}
		index++;
		stack = stack->next;
	}
	return (position);
}

/**
 * Ordena una pila de 4 elementos usando la de apoyo (stack_b).
 */
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest_position;

	smallest_position = get_position_of_smallest(*stack_a);
	if (smallest_position == 3)
		rra(stack_a);
	else if (smallest_position >= 1 && smallest_position <= 2)
	{
		while (smallest_position-- > 0)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

/**
 * Ordena una pila de 5 elementos usando la de apoyo (stack_b).
 */
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest_position;

	smallest_position = get_position_of_smallest(*stack_a);
	if (smallest_position >= 3 && smallest_position <= 4)
	{
		while (smallest_position++ < 5)
			rra(stack_a);
	}
	else if (smallest_position >= 1 && smallest_position <= 2)
	{
		while (smallest_position-- > 0)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/**
 * Ordena una pila de 6 elementos usando la de apoyo (stack_b).
 */
void	sort_six(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest_position;

	smallest_position = get_position_of_smallest(*stack_a);
	if (smallest_position >= 1 && smallest_position <= 3)
	{
		while (smallest_position-- > 0)
			ra(stack_a);
	}
	else if (smallest_position >= 4 && smallest_position <= 5)
	{
		while (smallest_position++ < 6)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_five(stack_a, stack_b);
	pa(stack_a, stack_b);
}
