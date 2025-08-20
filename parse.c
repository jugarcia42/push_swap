#include "push_swap.h"

/**
 * Une todos los argumentos pasados en argv en un único array de strings
 * (separando correctamente por espacios).
 */
static char	**split_all_arguments(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**temp;
	char	**final_args;

	i = 1;
	k = 0;
	final_args = malloc(sizeof(char *) * (count_arguments(argv) + 1));
	if (!final_args)
		return (NULL);
	while (argv[i])
	{
		j = 0;
		temp = ft_split(argv[i], ' ');
		while (temp[j])
		{
			final_args[k] = ft_strdup(temp[j]);
			free(temp[j++]);
			k++;
		}
		free(temp);
		i++;
	}
	final_args[k] = NULL;
	return (final_args);
}

/**
 * Verifica si el argumento está vacío o contiene solo espacios.
 */
static int	is_empty_argument(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (1);
	while (arg[i])
	{
		if (arg[i] != ' ' && !(arg[i] >= 9 && arg[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Verifica si un argumento es un número válido.
 */
static int	is_not_number(char *arg)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (ft_isdigit(arg[i]) == 1)
	{
		i++;
		has_digit = 1;
	}
	if (arg[i] == '\0' && has_digit == 1)
		return (0);
	return (1);
}

/**
 * Libera el array de strings generado al procesar los argumentos.
 */
static void	free_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

/**
 * Parsea los argumentos del programa, valida que sean correctos
 * y los añade a la pila `stack_a`.
 *
 * Return:
 *  -1 → sin argumentos
 *   0 → correcto
 *   1 → error
 */
int	parse_arguments(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		num;
	int		overflow;
	char	**args;

	if (argc == 1)
		return (-1);
	i = 1;
	while (argc > i)
	{
		if (is_empty_argument(argv[i++]))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	args = split_all_arguments(argv);
	i = 0;
	overflow = 0;
	while (args[i])
	{
		num = ft_atoi_overflow(args[i], &overflow);
		if (is_not_number(args[i++]) || overflow)
			return (free_arguments(args), ft_putstr_fd("Error\n", 2), 1);
		stack_add_back(stack_a, stack_new(num));
	}
	free_arguments(args);
	return (0);
}