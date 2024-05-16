/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:45:00 by ks19              #+#    #+#             */
/*   Updated: 2024/05/16 10:53:13 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pushback_to_a(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	var->z = 0;
	while (*stack_b)
	{
		var->size_a = ft_listsize(*stack_a);
		var->z = ft_calculate_cost_to_a(*stack_a, *stack_b, var);
		if (var->z <= var->size_a / 2)
		{
			while (var->z > 0)
			{
				ft_ra(stack_a, 0);
				var->z--;
			}
		}
		else
		{
			var->k = var->size_a - var->z;
			while (var->k > 0)
			{
				ft_rra(stack_a, 0);
				var->k--;
			}
		}
		ft_pa(stack_a, stack_b, 0);
	}
	ft_rotate_a(stack_a, var);
}

void	ft_sort_three(t_stack **stack_a, t_var *var)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 0);
		if (!ft_checksorted(*stack_a, var))
			ft_sa(stack_a, 0);
	}
	else
	{
		ft_sa(stack_a, 0);
		if (!ft_checksorted(*stack_a, var))
			ft_sort_three(stack_a, var);
	}
}

void	ft_move_to_b_till_3(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	while (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a, var))
	{
		ft_initialize_main(*stack_a, *stack_b, var);
		if (var->cost_a <= var->size_a / 2 && var->cost_b <= var->size_b / 2)
		{
			if (var->cost_b > 0 && var->cost_a > 0 && var->cost_b < var->cost_a)
				ft_rr_and_ra(stack_a, stack_b, var);
			else if (var->cost_b > 0 && var->cost_a > 0
				&& var->cost_b >= var->cost_a)
				ft_rr_and_rb(stack_a, stack_b, var);
			else
				ft_ra_or_rb(stack_a, stack_b, var);
		}
		else if (var->cost_a < var->size_a / 2 && var->cost_b > var->size_b / 2)
			ft_ra_and_rrb(stack_a, stack_b, var);
		else
		{
			if (var->cost_a >= var->size_a / 2 && var->cost_b > var->size_b / 2)
				ft_rrr_and_rrb(stack_a, stack_b, var);
			else
				ft_rra_and_rb(stack_a, stack_b, var);
		}
		ft_pb(stack_a, stack_b, 0);
	}
}

t_stack	*ft_sort_b(t_stack **stack_a, t_var *var)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a, var))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a, var))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a, var))
		ft_move_to_b_till_3(stack_a, &stack_b, var);
	if (ft_checksorted(*stack_a, var))
		ft_sortsorted(stack_a, var);
	else
		ft_sort_three(stack_a, var);
	return (stack_b);
}

void	ft_sort(t_stack **stack_a, t_var *var)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_listsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a, var);
	}
	ft_pushback_to_a(stack_a, &stack_b, var);
}
