/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:59 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:04 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init(int	*vector, int n, t_stack *a, t_stack *b)
{
	a->n = n;
	a->arr = vector;
	b->arr = ft_calloc(n, sizeof(int));
	if (b ->arr == NULL)
	{
		free(vector);
		return (1);
	}
	b->n = 0;
	return (0);
}

int	ft_calc(t_stack *a, t_stack *b, int i, int j)
{
	long long	min0;
	long long	cur;

	cur = 1 + (max(i, j));
	min0 = cur;
	a->side = 0;
	cur = 1 + (j + a->n - i);
	if (cur < min0)
	{
		min0 = min(cur, min0);
		a->side = 1;
	}
	cur = 1 + (i + b->n - j);
	if (cur < min0)
	{
		min0 = min(cur, min0);
		a->side = 2;
	}
	cur = 1 + (max(a->n - i, b->n - j));
	if (cur < min0)
	{
		min0 = min(cur, min0);
		a->side = 3;
	}
	return (min0);
}

void	ft_sort_three(t_stack *a)
{
	int	min0;
	int	max0;

	min0 = min(a->arr[0], min(a->arr[1], a->arr[2]));
	max0 = max(a->arr[0], max(a->arr[1], a->arr[2]));
	if (min0 == a->arr[0])
	{
		if (max0 == a->arr[1])
		{
			ft_swap(a, 0);
			ft_rot(a, 0);
		}
	}
	else if (min0 == a->arr[1])
	{
		if (max0 == a->arr[0])
			ft_rot(a, 0);
		else
			ft_swap(a, 0);
	}
	else
		ft_sort_three_part_two(a, max0);
}

void	ft_sort_three_part_two(t_stack *a, int max0)
{
	if (max0 == a->arr[1])
		ft_rrot(a, 0);
	else
	{
		ft_swap(a, 0);
		ft_rrot(a, 0);
	}
}

int	ft_sort_manual(t_stack *a)
{
	if (a->n == 3)
		ft_sort_three(a);
	if (a->n == 2)
		ft_swap(a, 0);
	return (1);
}
