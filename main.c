#include "push_swap.h"

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
	}
	else
		a = stack_init(argv + 1);

	// if (!stack_sorted(a))
	// 	sort_stack(a, b);
	print_stack(a);
	if (splitted_argv)
		free_split(splitted_argv);
	free_stack(&a);
	return (0);
}

void	print_stack(t_stack	*a)
{
	t_node *current;

	current = a->bottom;
	for ( ; current; )
	{
		ft_putnbr_fd(current->value, 1);
		write(1, " ", 1);
		current = current->next;
	}
	write(1, "\n", 1);
}

// void	sort_stack(t_stack *a, t_stack *b)
// {
// 	int	len;

// 	b = malloc(sizeof(t_stack));
// 	if (!b)
// 		return ;
// 	len = stack_len(a);
// 	if (len == 2)
// 		sa(a);
// 	else if (len == 3)
// 		sort_three(a);
// 	else
// 		radix_sort(a, b);
// 	}
	
t_stack	*stack_init(char **argv)
{
	long long	nbr;
	int			i;
	t_stack		*a;

	a = malloc(sizeof(t_stack));
	// if (!a)
	// 	return ;
	a->size = 0;
	a->top = NULL;
	a->bottom = NULL;
	i = 0;
	while (argv[i])
	{
		// if (error_syntax(argv[i]))
		// 	error_free(a, argv);
		nbr = ft_atol(argv[i]);
		// if (nbr > INT_MAX || nbr < INT_MIN)
		// 	error_free(a, argv);
		// if (error_repetition(a, (int)nbr))
		// 	error_free(a, argv);
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
		node->prev = a->top;
		a->top->next = node;
		a->top = node;
	}
	a->size++;
}

int	error_syntax(char *nbr)
{
	if (!(*nbr == '+'
			|| *nbr == '-'
			|| (*nbr >= '0' && *nbr <= '9')))
		return (1);
	if ((*nbr == '+'
			|| *nbr == '-')
		&& !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	nbr++;
	while (*nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (1);
		nbr++;
	}
	return (0);
}

int	error_repetition(t_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

long long	ft_atol(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13)
		|| nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error_free(t_node **a, t_node **b, char **argv)
{
	if (a)
	{
		free_stack(a);
		a = NULL;
	}
	if (b)
	{
		free_stack(b);
		b = NULL;
	}	
	free_split(argv);
	write(2, "Error\n", 6);
	// exit(1);
}
