/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:34:09 by wschafer          #+#    #+#             */
/*   Updated: 2025/10/22 13:34:12 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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