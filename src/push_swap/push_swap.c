# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

#include "../../includes/push_swap.h"


t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;	
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a = NULL;
	t_var var;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}

	if (ft_checksorted(a)){
		ft_sortsorted(&a);
	}
	else {
		ft_sort(&a, &var);
	}
	// if (a)
	// {	
	// 	printf("This is the stack a after:\n");
	// 	t_stack *current = a;
	// 	while (current){
	// 		 printf("%ld\n", current->nbr);
	// 		 current = current->next;
	// 	}
	// }
	int i = 0;
	if (a)
	{
		printf("Checking if everyting is in ascending order...\n");
		t_stack *current1 = a;
		while (current1!= NULL && current1->next->nbr > current1->nbr)
		{	
			i++;
			 current1 = current1->next;
			 if (current1->next == NULL){
			 	break;
			 }
		}
		printf("Everything is ok if i is %d!\n", i);
	}
	ft_free(&a);
	return (0);
}

