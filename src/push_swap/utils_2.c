#include "../../includes/push_swap.h"

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

void	ft_sortsorted(t_stack **stack_a, t_var *var)
{

	var->pos = ft_min_pos(*stack_a);
	var->size_a = ft_listsize(*stack_a);

	if (var->pos <= var->size_a / 2){
		while(var->pos > 0){
		ft_ra(stack_a, 0);
		var->pos--;
		}
	}
	else{
		var->g = var->size_a - var->pos;
		while(var->g > 0){
			ft_rra(stack_a, 0);
			var->g--;
		}
	}
}

t_stack *copyList(t_stack *head) 
{ 
	if (head == NULL) { 
		return NULL; 
	} 
	else { 

		// Allocate the memory for new Node 
		// in the heap and set its data 
		t_stack *newNode 
			= (t_stack*)malloc( 
				sizeof(t_stack)); 

		newNode->nbr = head->nbr; 

		// Recursively set the next pointer of 
		// the new Node by recurring for the 
		// remaining nodes 
		newNode->next = copyList(head->next); 

		return newNode; 
	} 
} 

void ft_rotate_to_min(t_stack **current, t_var *var){
	
	var->pos = ft_min_pos(*current);
	var->size_a = ft_listsize(*current);

	if (var->pos <= var->size_a / 2){
		while(var->pos > 0){
		ft_ra(current, 1);
		var->pos--;
		}
	}
	else{
		var->g = var->size_a - var->pos;
		while(var->g > 0){
			ft_rra(current, 1);
			var->g--;
		}
	}
}

int	ft_checksorted(t_stack *stack_a, t_var *var)
{

	t_stack *current;

	current = copyList(stack_a);
	ft_rotate_to_min(&current, var);
	var->i = current->nbr;
	while (current)
	{
		if (var->i > current->nbr)
			return (0);
		var->i = current->nbr;
		current = current->next;
	}
	ft_free(&current);
	return (1);
}