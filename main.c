/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:24:17 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:38 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fix_two(t_stack *a, int p, int id)
{
	int	i;

	i = id;
	if (i < (a->n - i))
	{
		while (i)
		{
			i--;
			ft_rot(a, p);
		}
	}
	else
	{
		while (i < a->n)
		{
			ft_rrot(a, p);
			i++;
		}
	}
}

void	ft_fix(t_stack *a, int p)
{
	int	i;
	int	id;
	int	min0;

	i = 0;
	id = 0;
	min0 = a->arr[0];
	while (i < a->n)
	{
		if (min0 > a->arr[i])
		{
			id = i;
			min0 = a->arr[i];
		}
		i++;
	}
	ft_fix_two(a, p, id);
}

void	ft_add_back(t_stack *b, t_stack *a)
{
	int	min0;
	int	k;

	min0 = min(a->arr[0], b->arr[0]);
	k = 0;
	while (b->n)
	{
		if (b->arr[0] < a->arr[0] || (min0 == a->arr[0] && k == 1))
		{
			ft_push(b, a, 1);
			ft_rot(a, 0);
		}
		else
		{
			ft_rot(a, 0);
			k = 1;
		}
	}
}

int	pre_sorting(t_stack *a, t_stack *b, int i, int g)
{
	int	y;
	int	*inc;

	y = 0;
	inc = longest_increasing_subsequence(a->arr, a->n, &y);
	if (y >= 4)
	{
		i = 0;
		g = a->n;
		while (g)
		{
			if (i < y && inc[i] == a->arr[0])
			{
				ft_rot(a, 0);
				i++;
			}
			else
				ft_push(a, b, 0);
			g--;
		}
		free(inc);
		return (1);
	}
	free(inc);
	return (0);
}

int	main(int n, char **arr)
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (n == 1 || ft_parse(n, arr, &a, &b))
		return (1);
	i = 1;
	while (i < a.n && a.arr[i] > a.arr[i - 1])
		i++;
	if (i == a.n && fr_int(&a.arr) && fr_int(&b.arr))
		return (0);
	if (a.n <= 3 && ft_sort_manual(&a) && fr_int(&a.arr) && fr_int(&b.arr))
		return (0);
	if (!pre_sorting(&a, &b, 0, 0))
	{
		while (a.n > 3)
			ft_push(&a, &b, 0);
		ft_sort_manual(&a);
	}
	while (b.n != 0 && ft_sort(&b, &a))
		;
	ft_fix(&a, 0);
	free(a.arr);
	free(b.arr);
	return (0);
}
