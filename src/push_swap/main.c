/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:37:17 by ks19              #+#    #+#             */
/*   Updated: 2024/06/22 23:58:49 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
//ici on envoyait l & de a car si tu envoies a slmt alors a 
//chq iteration a = NULL, dans add back on aurait a chq fois un 
//stack_new
//mais ca marche si tu gardes l & de a dans ta fonction qui loop
t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	printf("first a & is:%p\n", a);
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			// ft_add_back(&a, ft_stack_new(j));
			a = ft_add_test(a, ft_stack_new(j));
			printf("%p\n", a);
			i++;
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *current;
	t_var	var;

	a = NULL;
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (ft_checksorted(a, &var))
	{
		ft_sortsorted(&a, &var);
	}
	else
	{
		ft_sort(&a, &var);
	}
	current = a;
	while(current)
	{
		printf("%ld\n", current->nbr);
		current = current->next;
	}
	// ft_free(var);
	ft_free(&a);
	return (0);
}
