/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:40:29 by ks19              #+#    #+#             */
/*   Updated: 2024/05/16 10:51:17 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (var->pos <= var->size_a / 2)
	{
		while (var->pos > 0)
		{
			ft_ra(stack_a, 0);
			var->pos--;
		}
	}
	else
	{
		var->g = var->size_a - var->pos;
		while (var->g > 0)
		{
			ft_rra(stack_a, 0);
			var->g--;
		}
	}
}

// Allocate the memory for new Node
// in the heap and set its data
// Recursively set the next pointer of
// the new Node by recurring for the
// remaining nodes
t_stack	*copylist(t_stack *head)
{
	t_stack	*new_node;

	if (head == NULL)
	{
		return (NULL);
	}
	else
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->nbr = head->nbr;
		new_node->next = copylist(head->next);
		return (new_node);
	}
}

void	ft_rotate_to_min(t_stack **current, t_var *var)
{
	var->pos = ft_min_pos(*current);
	var->size_a = ft_listsize(*current);
	if (var->pos <= var->size_a / 2)
	{
		while (var->pos > 0)
		{
			ft_ra(current, 1);
			var->pos--;
		}
	}
	else
	{
		var->g = var->size_a - var->pos;
		while (var->g > 0)
		{
			ft_rra(current, 1);
			var->g--;
		}
	}
}

int	ft_checksorted(t_stack *stack_a, t_var *var)
{
	t_stack	*current;

	current = copylist(stack_a);
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
