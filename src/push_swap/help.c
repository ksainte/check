#include "../../includes/push_swap.h"



int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}
void	ft_sortsorted(t_stack **stack_a)
{
	int pos;
	int size_a;
	int g;


	pos = ft_min_pos(*stack_a);
	size_a = ft_listsize(*stack_a);

	if (pos <= size_a / 2){
		while(pos > 0){
		ft_ra(stack_a, 0);
		pos--;
		}
	}
	else{
		g = size_a - pos;
		while(g > 0){
			ft_rra(stack_a, 0);
			g--;
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

int	ft_checksorted(t_stack *stack_a)
{
	int	i;
	int pos;
	int size_a;
	int g;
	t_stack *current;


	pos = ft_min_pos(stack_a);
	size_a = ft_listsize(stack_a);

	current = copyList(stack_a);
	if (pos <= size_a / 2){
		while(pos > 0){
		ft_ra(&current, 1);
		pos--;
		}
	}
	else{
		g = size_a - pos;
		while(g > 0){
			ft_rra(&current, 1);
			g--;
		}
	}
	i = current->nbr;
	while (current)
	{
		if (i > current->nbr)
			return (0);
		i = current->nbr;
		current = current->next;
	}
	return (1);
}

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}



void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lastnode(*stack))->next = stack_new;
}



t_stack	*ft_lastnode(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}


int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}



