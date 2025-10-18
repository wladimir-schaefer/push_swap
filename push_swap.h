#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;

	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// main.c
int		main(int argc, char **argv);
void	stack_init(t_stack	*a, char **argv, int flag);
long	ft_atol(const char *nptr);

#endif