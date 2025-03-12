/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_part_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:59 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:07 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two_ft_root(t_stack *a, t_stack *b)
{
	ft_rot(a, -1);
	ft_rot(b, -1);
}

long long	ft_abs(long long ans)
{
	if (ans < 0)
		return (-ans);
	return (ans);
}

int	ft_sort_loop_loop(t_stack *a, t_stack *b, int i)
{
	int			j;
	long long	y;
	int			u;

	j = 0;
	y = 1e18;
	u = 0;
	while (j < b->n)
	{
		if (y > ft_abs(a->arr[i] * 1LL - b->arr[j] * 1LL))
		{
			y = ft_abs(a->arr[i] * 1LL - b->arr[j] * 1LL);
			if (a->arr[i] >= b->arr[j])
				u = j + 1;
			else
				u = j;
		}
		j++;
	}
	return (u);
}

void	ft_sort_loop(t_stack *a, t_stack *b, int *id0, int *id1)
{
	int			i;
	long long	min0;
	int			u;
	int			l;
	int			yy;

	min0 = 1e18;
	i = 0;
	while (i < a->n)
	{
		u = ft_sort_loop_loop(a, b, i);
		yy = a->side;
		l = ft_calc(a, b, i, u);
		if (l < min0)
		{
			min0 = l;
			*id0 = i;
			*id1 = u;
		}
		else
			a->side = yy;
		i++;
	}
}

int	ft_sort(t_stack *a, t_stack *b)
{
	int			id0;
	int			id1;

	id0 = -1;
	id1 = 0;
	ft_sort_loop(a, b, &id0, &id1);
	if (id0 == -1)
		return (0);
	ft_sort_elem(a, b, id0, id1);
	return (1);
}
