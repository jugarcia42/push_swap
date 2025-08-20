#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*prev;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	end = *stack;
	prev = *stack;
	while (end->next != NULL)
		end = end->next;
	while (prev->next->next != NULL)
		prev = prev->next;
	tmp = *stack;
	*stack = end;
	(*stack)->next = tmp;
	prev->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}