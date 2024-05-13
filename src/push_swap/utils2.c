#include "../../includes/push_swap.h"

// This function checks the index of a number
// 	 in the stack.
int	ft_find_index(t_stack *b, int nbr)
{
	int		i;

	i = 0;
	while (b->nbr != nbr)
	{
		i++;
		b = b->next;
	}
	b->index = 0;
	return (i);
}

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}