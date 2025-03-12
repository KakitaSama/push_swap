/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:11:51 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:48:08 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_part_three(t_stack *a, t_stack *b, char *s)
{
	if (cmp(s, "rr"))
	{
		ft_rot(a, -1);
		ft_rot(b, -1);
	}
	else if (cmp(s, "rra"))
		ft_rrot(a, -1);
	else if (cmp(s, "rrb"))
		ft_rrot(b, -1);
	else if (cmp(s, "rrr"))
	{
		ft_rrot(a, -1);
		ft_rrot(b, -1);
	}
	else
		return (0);
	return (1);
}

int	ft_check_part_two(t_stack *a, t_stack *b, char *s)
{
	if (cmp(s, "pb"))
	{
		if (a->n >= 1)
			ft_push(a, b, -1);
	}
	else if (cmp(s, "ra"))
		ft_rot(a, -1);
	else if (cmp(s, "rb"))
		ft_rot(b, -1);
	else
		return (ft_check_part_three(a, b, s));
	return (1);
}

int	ft_check_part_one(t_stack *a, t_stack *b, char *s)
{
	if (cmp(s, "sa"))
	{
		if (a->n >= 2)
			ft_swap(a, -1);
	}
	else if (cmp(s, "sb"))
	{
		if (b->n >= 2)
			ft_swap(b, -1);
	}
	else if (cmp(s, "ss"))
	{
		if (a->n >= 2)
			ft_swap(a, -1);
		if (b->n >= 2)
			ft_swap(b, -1);
	}
	else if (cmp(s, "pa"))
	{
		if (b->n >= 1)
			ft_push(b, a, -1);
	}
	else
		return (ft_check_part_two(a, b, s));
	return (1);
}
