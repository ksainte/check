/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:38:26 by ks19              #+#    #+#             */
/*   Updated: 2024/05/16 10:38:44 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_max_pos(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
		{
			i = a->nbr;
			k = j;
		}
		a = a->next;
		j++;
	}
	return (k);
}

int	ft_min_pos(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
		{
			i = a->nbr;
			k = j;
		}
		a = a->next;
		j++;
	}
	return (k);
}

int	ft_min(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

t_stack	*ft_listlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
