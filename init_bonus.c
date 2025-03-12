/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:59 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:43 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
