/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:11:25 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:34 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack *a, int p)
{
	int	tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	if (p == 0)
		write(1, "sa\n", 3);
	else if (p == 1)
		write(1, "sb\n", 3);
}

void	ft_rot(t_stack *a, int p)
{
	int	tmp;
	int	i;
	int	tmp1;

	i = a->n - 1;
	tmp = a->arr[i];
	while (i >= 0)
	{
		tmp1 = a->arr[(i - 1 + a->n) % a->n];
		a->arr[(i - 1 + a->n) % a->n] = tmp;
		tmp = tmp1;
		i--;
	}
	if (p == 0)
		write(1, "ra\n", 3);
	else if (p == 1)
		write(1, "rb\n", 3);
}

void	ft_rrot(t_stack *a, int p)
{
	int	tmp;
	int	i;
	int	tmp1;

	i = 0;
	tmp = a->arr[0];
	while (i < a->n)
	{
		tmp1 = a->arr[(i + 1) % a ->n];
		a->arr[(i + 1) % a->n] = tmp;
		tmp = tmp1;
		i++;
	}
	if (p == 0)
		write(1, "rra\n", 4);
	else if (p == 1)
		write(1, "rrb\n", 4);
}

void	ft_push(t_stack *a, t_stack *b, int p)
{
	int	tmp;

	tmp = a->arr[0];
	ft_rot(a, -1);
	a->n--;
	b->n++;
	ft_rrot(b, -1);
	b->arr[0] = tmp;
	if (p == 0)
		write(1, "pb\n", 3);
	else if (p == 1)
		write(1, "pa\n", 3);
}
