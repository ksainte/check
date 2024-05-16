/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:54:02 by ks19              #+#    #+#             */
/*   Updated: 2024/05/16 09:55:16 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_initialize_cost(t_stack *stack_a, t_stack *stack_b, t_var *var)
{
	var->cost_a = 0;
	var->b = 0;
	var->z = ft_calculate_cost(stack_a, stack_b, var);
	var->og = var->z;
	var->size_a = ft_listsize(stack_a);
	var->size_b = ft_listsize(stack_b);
}

int	ft_calculate_b(t_stack *stack_a, t_stack *stack_b, t_var *var)
{
	ft_initialize_cost(stack_a, stack_b, var);
	while (stack_a)
	{
		var->cost_b = ft_calculate_cost(stack_a, stack_b, var);
		var->original_cost = var->cost_b;
		if (var->cost_a <= var->size_a / 2 && var->cost_b <= var->size_b / 2)
			ft_lower_and_or_lower(var);
		else if (var->cost_a < var->size_a / 2 && var->cost_b > var->size_b / 2)
			ft_lower_and_higher(var);
		else
		{
			if (var->cost_a >= var->size_a / 2 && var->cost_b > var->size_b / 2)
				ft_higher_and_higher(var);
			else
				ft_higher_and_lower(var);
		}
		if (var->cost_b < var->z)
			ft_new_least_exp_element(var);
		stack_a = stack_a->next;
		var->cost_a++;
	}
	return (var->b);
}
