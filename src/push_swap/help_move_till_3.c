/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_move_till_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:25:10 by ks19              #+#    #+#             */
/*   Updated: 2024/05/16 10:33:56 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_initialize_main(t_stack *stack_a, t_stack *stack_b, t_var *var)
{
	var->cost_a = ft_calculate_b(stack_a, stack_b, var);
	var->cost_b = var->og;
	var->size_b = ft_listsize(stack_b);
	var->size_a = ft_listsize(stack_a);
}

void	ft_rr_and_ra(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->k = var->cost_a - var->cost_b;
	while (var->cost_b > 0)
	{
		ft_rr(stack_a, stack_b, 0);
		var->cost_b--;
	}
	while (var->k > 0)
	{
		ft_ra(stack_a, 0);
		var->k--;
	}
}

void	ft_rr_and_rb(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->k = var->cost_b - var->cost_a;
	while (var->cost_a > 0)
	{
		ft_rr(stack_a, stack_b, 0);
		var->cost_a--;
	}
	while (var->k > 0)
	{
		ft_rb(stack_b, 0);
		var->k--;
	}
}

void	ft_ra_or_rb(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	while (var->cost_b > 0)
	{
		ft_rb(stack_b, 0);
		var->cost_b--;
	}
	while (var->cost_a > 0)
	{
		ft_ra(stack_a, 0);
		var->cost_a--;
	}
}

void	ft_rotate_a(t_stack **stack_a, t_var *var)
{
	var->size_a = ft_listsize(*stack_a);
	var->pos = ft_min_pos(*stack_a);
	var->k = ft_listsize(*stack_a) - var->pos;
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
		while (var->k > 0)
		{
			ft_rra(stack_a, 0);
			var->k--;
		}
	}
}
