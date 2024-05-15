#include "../../includes/push_swap.h"

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