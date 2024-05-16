/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_move_till_3_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:24:24 by ks19              #+#    #+#             */
/*   Updated: 2024/05/16 10:24:34 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra_and_rrb(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->k = var->size_b - var->cost_b;
	while (var->cost_a > 0)
	{
		ft_ra(stack_a, 0);
		var->cost_a--;
	}
	while (var->k > 0)
	{
		ft_rrb(stack_b, 0);
		var->k--;
	}
}

void	ft_rrr_and_rra(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->k = var->g - var->h;
	while (var->h > 0)
	{
		ft_rrr(stack_a, stack_b, 0);
		var->h--;
	}
	while (var->k > 0)
	{
		ft_rra(stack_a, 0);
		var->k--;
	}
}

void	ft_rrr_and_rrb(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->h = var->size_b - var->cost_b;
	var->g = var->size_a - var->cost_a;
	if (var->g <= var->h)
	{
		var->k = var->h - var->g;
		while (var->g > 0)
		{
			ft_rrr(stack_a, stack_b, 0);
			var->g--;
		}
		while (var->k > 0)
		{
			ft_rrb(stack_b, 0);
			var->k--;
		}
	}
	else
		ft_rrr_and_rra(stack_a, stack_b, var);
}

void	ft_rra_and_rb(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->g = var->size_a - var->cost_a;
	while (var->g > 0)
	{
		ft_rra(stack_a, 0);
		var->g--;
	}
	while (var->cost_b > 0)
	{
		ft_rb(stack_b, 0);
		var->cost_b--;
	}
}
