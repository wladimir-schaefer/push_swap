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
long long	ft_atol(const char *nptr);
void		sort_stack(t_stack *a, t_stack *b);
t_stack		*stack_init(char **argv);
void		append_node(t_stack *a, int nbr);
int			error_syntax(char *nbr);
int			error_repetition(t_node *a, int nbr);
void		free_split(char **arr);
void		error_free(t_node **a, char **argv);


void	print_stack(t_stack	*a);

#endif