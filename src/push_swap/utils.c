#include "../../includes/push_swap.h"


// This function finds and returns the smallest number
// in the given stack and its position
int	ft_max_pos(t_stack *a)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = a->nbr;
	while (a)
	{
		if (a->nbr > i){
			i = a->nbr;
			k = j;
		}
		a = a->next;
		j++;
	}
	return (k);
}

// This function finds and returns the smallest number
// in the given stack and its position
int	ft_min_pos(t_stack *a)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = a->nbr;
	while (a)
	{
		if (a->nbr < i){
			i = a->nbr;
			k = j;
		}
		a = a->next;
		j++;
	}
	return (k);
}

// This function finds and returns the smallest number
// in the given stack
int	ft_min(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

// This function finds and returns the biggest number
// in the given stack.
int	ft_max(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

// This function checks the index of a number
// 	 in the stack.
int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	ft_listsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_listlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}