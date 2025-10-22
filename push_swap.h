#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

// main.c
int			main(int argc, char **argv);
t_stack		*stack_init(char **argv);
void		append_node(t_stack *a, int nbr);
void		sort_stack(t_stack *a, t_stack *b);
int			if_stack_sorted(t_stack *a);

// utils_free.c
void		error_free(t_stack *a, t_stack *b);
void		free_stack(t_stack *stack);
void		free_split(char **arr);

// utils_error.c
int			error_syntax(char *nbr);
int			error_repetition(t_node *a, int nbr);
long long	ft_atol(const char *nptr);


/////////////////////////////////
void	print_stack(t_stack	*a);

#endif