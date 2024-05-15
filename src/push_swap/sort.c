#include "../../includes/push_swap.h"


void ft_rotate_a(t_stack **stack_a){
	
	int pos;
	int e;
	int size = 0;
	int avg = 0;

	size = ft_listsize(*stack_a);
	pos = ft_min_pos(*stack_a);
	e = ft_listsize(*stack_a) - pos;
	avg = size / 2;
	if (pos <= avg){
		while(pos > 0){
			ft_ra(stack_a, 0);
			pos--;
		}
	}
	else{
		while(e > 0){
			ft_rra(stack_a, 0);
			e--;
		}
	}
}


void ft_best_fit_in_b(t_stack **head_a, t_stack **head_b, t_var *var){

		while((*head_b)->next != NULL){
				if (var->i < (*head_b)->next->nbr && (*head_b)->next->nbr < (*head_a)->nbr){
					var->i = (*head_b)->next->nbr;
					*head_b = (*head_b)->next;
					var->j++;
					var->k = var->j;
				}
				else {
					(*head_b) = (*head_b)->next;
					var->j++;
				}
			}
}

void ft_skip_head(t_stack **head, t_var *var){

		var->i = (*head)->next->nbr;
		*head = (*head)->next;
		var->j++;
		var->k = var->j;
}

int ft_calculate_cost(t_stack *stack_a, t_stack *stack_b, t_var *var){

	if ((stack_a)->nbr < ft_min(stack_b)){
		var->pos = ft_max_pos(stack_b);
		return (var->pos);
	}
	t_stack *head_b;
	t_stack *head_a;
	head_b = copyList(stack_b);
	head_a = copyList(stack_a);
	var->j = 0;
	var->k = 0;
	var->i = head_b->nbr;
	while (head_b != NULL){
		if (head_a->nbr < var->i)
			ft_skip_head(&head_b, var);
		else {
			ft_best_fit_in_b(&head_a, &head_b, var);
			ft_free(&head_a);
			ft_free(&head_b);
			return(var->k);
		}
	}
	return(0);
}

void ft_best_fit_in_a(t_stack **head_a, t_stack **head_b, t_var *var){

	while((*head_a)->next != NULL){
		if (var->i > (*head_a)->next->nbr && (*head_a)->next->nbr > (*head_b)->nbr){
			var->i = (*head_a)->next->nbr;
			*head_a = (*head_a)->next;
			var->j++;
			var->k = var->j;
		}
		else {
			*head_a = (*head_a)->next;
			var->j++;
		}
	}
}


int ft_calculate_cost_to_a(t_stack *stack_a, t_stack *stack_b, t_var *var){

	if ((stack_b)->nbr > ft_max(stack_a)){
		var->pos = ft_min_pos(stack_a);
		return (var->pos);
	}
	t_stack *head_b;
	t_stack *head_a;
	head_b = copyList(stack_b);
	head_a = copyList(stack_a);
	var->j = 0;
	var->k = 0;
	var->i = head_a->nbr;
	while (head_a != NULL){
		if (head_b->nbr > var->i)
			ft_skip_head(&head_a, var);
		else {
			ft_best_fit_in_a(&head_a, &head_b, var);
			ft_free(&head_a);
			ft_free(&head_b);
			return(var->k);
		}
	}
	return(0);
}

void ft_lower_and_or_lower(t_var *var){
		
		if (var->cost_b > 0 && var->cost_a > 0 && var->cost_b < var->cost_a)
			var->cost_b = var->cost_a;
		else if (var->cost_b > 0 && var->cost_a > 0 && var->cost_b >= var->cost_a)
			var->cost_b = var->cost_b + 0;
		else
			var->cost_b = var->cost_b + var->cost_a;
}

void ft_lower_and_higher(t_var *var){
		
		var->cost_b = var->size_b - var->cost_b + var->cost_a;
}

void ft_higher_and_higher(t_var *var){
		
	var->h = var->size_b - var->cost_b;
	var->g = var->size_a - var->cost_a;
	
	if (var->g <= var->h)
		var->cost_b = var->h;
	else
		var->cost_b = var->g;
}

void ft_higher_and_lower(t_var *var){
		
	var->g = var->size_a - var->cost_a;
	var->cost_b = var->cost_b + var->g;
}

void ft_new_least_exp_element(t_var *var){
					
	var->z = var->cost_b;//keep track of the lowest cost combined
	var->b = var->cost_a;//keep track of the Least Expensive element in stack a(index)
	var->og = var->original_cost;
}

void ft_initialize_cost(t_stack *stack_a, t_stack *stack_b, t_var *var){

			var->cost_a = 0;
			var->b = 0;
			var->z = ft_calculate_cost(stack_a, stack_b, var);
			var->og = var->z;
			var->size_a = ft_listsize(stack_a);
			var->size_b = ft_listsize(stack_b);
}

int ft_calculate_b(t_stack *stack_a, t_stack *stack_b, t_var *var){

			ft_initialize_cost(stack_a, stack_b, var);

			while(stack_a){
				var->cost_b = ft_calculate_cost(stack_a, stack_b, var);
				var->original_cost = var->cost_b;
				if (var->cost_a <= var->size_a / 2 && var->cost_b <= var->size_b / 2)
					ft_lower_and_or_lower(var);
				else if (var->cost_a < var->size_a / 2 && var->cost_b > var->size_b / 2)
					ft_lower_and_higher(var);
				else{
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
			return(var->b);
}

void ft_rr_and_ra(t_stack **stack_a, t_stack **stack_b, t_var *var){
	
		var->k = var->cost_a - var->cost_b;
		while(var->cost_b > 0){
			ft_rr(stack_a, stack_b, 0);
			var->cost_b--;
		}
		while(var->k > 0){
			ft_ra(stack_a, 0);
			var->k--;
		}
}

void ft_rr_and_rb(t_stack **stack_a, t_stack **stack_b, t_var *var){
	
	var->k = var->cost_b - var->cost_a;
	while(var->cost_a > 0){
		ft_rr(stack_a, stack_b, 0);
		var->cost_a--;
	}
	while(var->k > 0){
		ft_rb(stack_b, 0);
		var->k--;
	}
}

void ft_ra_or_rb(t_stack **stack_a, t_stack **stack_b, t_var *var){
	
	while(var->cost_b > 0){
		ft_rb(stack_b, 0);
		var->cost_b--;
	}
	while(var->cost_a > 0){
		ft_ra(stack_a, 0);
		var->cost_a--;
	}
}

void ft_ra_and_rrb(t_stack **stack_a, t_stack **stack_b, t_var *var){
	
	var->k = var->size_b - var->cost_b;
	while(var->cost_a > 0){
		ft_ra(stack_a, 0);
		var->cost_a--;
	}
	while(var->k > 0){
		ft_rrb(stack_b, 0);
		var->k--;
	}
}

void ft_rrr_and_rra(t_stack **stack_a, t_stack **stack_b, t_var *var){
	
	var->k = var->g - var->h;
	while(var->h > 0){
		ft_rrr(stack_a, stack_b, 0);
		var->h--;
	}
	while(var->k > 0){
		ft_rra(stack_a, 0);
		var->k--;
	}
}

void ft_rrr_and_rrb(t_stack **stack_a, t_stack **stack_b, t_var *var){

	var->h = var->size_b - var->cost_b;
	var->g = var->size_a - var->cost_a;
	
	if (var->g <= var->h){
		var->k = var->h - var->g;
		while(var->g > 0){
			ft_rrr(stack_a, stack_b, 0);
			var->g--;
		}
		while(var->k > 0){
			ft_rrb(stack_b, 0);
			var->k--;
		}
	}
	else
		ft_rrr_and_rra(stack_a, stack_b, var);
}

void ft_rra_and_rb(t_stack **stack_a, t_stack **stack_b, t_var *var){
	
	var->g = var->size_a - var->cost_a;
	while(var->g > 0){
		ft_rra(stack_a, 0);
		var->g--;
	}
	while(var->cost_b > 0){
		ft_rb(stack_b, 0);
		var->cost_b--;
	}
}

void ft_initialize_main(t_stack *stack_a, t_stack *stack_b, t_var *var){

			var->cost_a = ft_calculate_b(stack_a, stack_b, var);
			var->cost_b = var->og;
			var->size_b = ft_listsize(stack_b);
			var->size_a = ft_listsize(stack_a);
}

void	ft_move_to_b_till_3(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	while (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
	{
			ft_initialize_main(*stack_a, *stack_b, var);
			if (var->cost_a <= var->size_a / 2 && var->cost_b <= var->size_b / 2){
					if (var->cost_b > 0 && var->cost_a > 0 && var->cost_b < var->cost_a)
						ft_rr_and_ra(stack_a, stack_b, var);
					else if (var->cost_b > 0 && var->cost_a > 0 && var->cost_b >= var->cost_a)
						ft_rr_and_rb(stack_a, stack_b, var);
					else
						ft_ra_or_rb(stack_a, stack_b, var);
			}
			else if (var->cost_a < var->size_a / 2 && var->cost_b > var->size_b / 2)
					ft_ra_and_rrb(stack_a, stack_b, var);
			else{
					if (var->cost_a >= var->size_a / 2 && var->cost_b > var->size_b / 2)
						ft_rrr_and_rrb(stack_a, stack_b, var);
					else
						ft_rra_and_rb(stack_a, stack_b, var);
				}
				ft_pb(stack_a, stack_b, 0);
			}
}



void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 0);
		if (!ft_checksorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		ft_sa(stack_a, 0);
		if (!ft_checksorted(*stack_a))
			ft_sort_three(stack_a);
	}
}

t_stack	*ft_sort_b(t_stack **stack_a, t_var *var)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_listsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_move_to_b_till_3(stack_a, &stack_b, var);
	if (ft_checksorted(*stack_a)){
		ft_sortsorted(stack_a);
	}
	else
		ft_sort_three(stack_a);
	return (stack_b);
}

void ft_pushback_to_a(t_stack **stack_a, t_stack **stack_b, t_var *var){

	int z = 0;
	int size_a;
	int k;

	while(*stack_b){
		size_a = ft_listsize(*stack_a);
		z = ft_calculate_cost_to_a(*stack_a, *stack_b, var);
		if (z <= size_a / 2){
			while (z > 0){
				ft_ra(stack_a, 0);
				z--;
			}
		}
		else{
			k = size_a - z;
			while(k > 0){
				ft_rra(stack_a, 0);
				k--;
			}
		}
		ft_pa(stack_a, stack_b, 0);
	}
	ft_rotate_a(stack_a);
}

void	ft_sort(t_stack **stack_a, t_var *var)
{
    t_stack	*stack_b;

	stack_b = NULL;
	if (ft_listsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
    else{
        stack_b = ft_sort_b(stack_a, var);
	}
	ft_pushback_to_a(stack_a, &stack_b, var);
}

