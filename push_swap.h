#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

/* ================= STRUCT ================= */
typedef struct s_stack
{
	int				value;   // Valor real (número del input)
	int				index;   // Índice en el orden creciente
	struct s_stack	*next;   // Apuntador al siguiente nodo
}	t_stack;

/* ================= PARSING ================= */
int		parse_arguments(int argc, char **argv, t_stack **stack_a);
int		parse_stack(t_stack *stack_a);
int		count_arguments(char **argv);

/* ================= STACK UTILS ============= */
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

/* ================= INDEX / K-SORT ========== */
void	assign_sorted_index(t_stack **stack_a);
void	sort_in_groups(t_stack **stack_a, t_stack **stack_b, int total);
void	sort_back_to_a(t_stack **stack_a, t_stack **stack_b);

/* ================= SORT SMALL ============== */
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_six(t_stack **stack_a, t_stack **stack_b);

/* ================= OPERATIONS ============== */
// Swap
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// Push
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// Rotate
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// Reverse Rotate
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif