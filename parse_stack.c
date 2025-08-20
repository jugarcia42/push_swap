#include "push_swap.h"

/**
 * Comprueba si en la pila existen números duplicados.
 * Devuelve 1 si encuentra duplicados, 0 si no.
 */
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

/**
 * Comprueba si la pila está ya ordenada de menor a mayor.
 * Devuelve 1 si está ordenada, 0 si no.
 */
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

/**
 * Libera la memoria de toda la pila.
 */
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

/**
 * Valida el contenido de la pila:
 *  - Error si hay duplicados → retorna 1
 *  - Ya está ordenada        → retorna -1
 *  - Correcto                → retorna 0
 */
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