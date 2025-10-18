#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], " ");
		stack_init(&a, argv, 1);
	}
	else
		stack_init(&a, argv + 1, 0);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free(&a);
	return (0);
}

void	stack_init(t_stack	*a, char **argv, int if_split)
{
	long	nbr;
	int		i;

	i =0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv);
		if (error_repetition(a, (int)nbr))
			error_free(a, argv);
		append_node(a, (int)nbr);
		++i;
	}
	if (if_split)
		free_split(argv);
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

int	error_repetition(t_stack *a, int nbr)
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

long	ft_atol(const char *nptr)
{
	size_t		i;
	int			sign;
	long		res;

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

