#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**splitted_argv;

	splitted_argv = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		splitted_argv = ft_split(argv[1], ' ');
		a = stack_init(splitted_argv);
		free_split(splitted_argv);
	}
	else
		a = stack_init(argv + 1);
	if (!if_stack_sorted(a))
		sort_stack(a, b);
	else

	print_stack(a);
	printf("top - %d\n", a->top->value);
	printf("bottom - %d\n", a->bottom->value);
	free_stack(a);
	return (0);
}

int	if_stack_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (0);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// void	sort_stack(t_stack *a, t_stack *b)
// {
// 	int	len;

// 	b = malloc(sizeof(t_stack));
// 	if (!b)
// 		return ;
// 	len = a->size;
// 	if (len == 2)
// 		sa(a);
// 	else if (len == 3)
// 		sort_three(a);
// 	else
// 		radix_sort(a, b);
// }
	
t_stack	*stack_init(char **argv)
{
	long long	nbr;
	int			i;
	t_stack		*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->size = 0;
	a->top = NULL;
	a->bottom = NULL;
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, NULL);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, NULL);
		if (error_repetition(a->bottom, (int)nbr))
			error_free(a, NULL);
		append_node(a, (int)nbr);
		i++;
	}
	return (a);
}

void	append_node(t_stack *a, int nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = nbr;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	if (!a->top)
	{
		a->top = node;
		a->bottom = node;
	}
	else
	{
		node->prev = a->bottom;
		a->bottom->next = node;
		a->bottom = node;
	}
	a->size++;
}




void	print_stack(t_stack	*a)
{
	t_node *current;

	current = a->top;
	for ( ; current; )
	{
		ft_putnbr_fd(current->value, 1);
		write(1, " ", 1);
		current = current->next;
	}
	write(1, "\n", 1);
}
