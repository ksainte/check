/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_calculate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:11:32 by ks19              #+#    #+#             */
/*   Updated: 2024/05/16 10:13:49 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lower_and_or_lower(t_var *var)
{
	if (var->cost_b > 0 && var->cost_a > 0 && var->cost_b < var->cost_a)
		var->cost_b = var->cost_a;
	else if (var->cost_b > 0 && var->cost_a > 0 && var->cost_b >= var->cost_a)
		var->cost_b = var->cost_b + 0;
	else
		var->cost_b = var->cost_b + var->cost_a;
}

void	ft_lower_and_higher(t_var *var)
{
	var->cost_b = var->size_b - var->cost_b + var->cost_a;
}

void	ft_higher_and_higher(t_var *var)
{
	var->h = var->size_b - var->cost_b;
	var->g = var->size_a - var->cost_a;
	if (var->g <= var->h)
		var->cost_b = var->h;
	else
		var->cost_b = var->g;
}

void	ft_higher_and_lower(t_var *var)
{
	var->g = var->size_a - var->cost_a;
	var->cost_b = var->cost_b + var->g;
}

//keep track of the lowest cost combined
//keep track of the Least Expensive element in stack a(index)
void	ft_new_least_exp_element(t_var *var)
{
	var->z = var->cost_b;
	var->b = var->cost_a;
	var->og = var->original_cost;
}
