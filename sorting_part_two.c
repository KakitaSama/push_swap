/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_part_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:59 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:05 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sub_sort_elem_one(t_stack *a, t_stack *b, int i, int j)
{
	int	u;

	u = 0;
	while (u < min(i, j))
	{
		ft_two_ft_root(a, b);
		write(1, "rr\n", 3);
		u++;
	}
	if (i > j)
	{
		while (u < i)
		{
			u++;
			ft_rot(a, 1);
		}
	}
	else
	{
		while (u < j)
		{
			u++;
			ft_rot(b, 0);
		}
	}
}

void	ft_sub_sort_elem_two(t_stack *a, t_stack *b, int i, int j)
{
	int	u;

	u = 0;
	while (u < i)
	{
		ft_rot(a, 1);
		u++;
	}
	u = j;
	while (u < b->n)
	{
		ft_rrot(b, 0);
		u++;
	}
}

void	ft_sub_sort_elem_three(t_stack *a, t_stack *b, int i, int j)
{
	int	u;

	u = i;
	while (u < a->n)
	{
		ft_rrot(a, 1);
		u++;
	}
	u = 0;
	while (u < j)
	{
		ft_rot(b, 0);
		u++;
	}
}

void	ft_sub_sort_elem_four(t_stack *a, t_stack *b, int i, int j)
{
	while (i < a->n && j < b->n)
	{
		ft_rrot(b, -1);
		ft_rrot(a, -1);
		write(1, "rrr\n", 4);
		i++;
		j++;
	}
	while (i < a->n)
	{
		ft_rrot(a, 1);
		i++;
	}
	while (j < b->n)
	{
		ft_rrot(b, 0);
		j++;
	}
}

void	ft_sort_elem(t_stack *a, t_stack *b, int i, int j)
{
	int	k;

	k = a->side;
	if (k == 0)
		ft_sub_sort_elem_one(a, b, i, j);
	else if (k == 2)
		ft_sub_sort_elem_two(a, b, i, j);
	else if (k == 1)
		ft_sub_sort_elem_three(a, b, i, j);
	else
		ft_sub_sort_elem_four(a, b, i, j);
	ft_push(a, b, 1);
}
