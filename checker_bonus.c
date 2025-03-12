/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:11:51 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:48:10 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	cmp(char *s, char *t)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	while (t[j] && t[j] != '\n')
		j++;
	if (i != j)
		return (0);
	len = i;
	i = 0;
	while (i < len && s[i] == t[i])
		i++;
	return (i == len);
}

int	ft_sorted(t_stack *a, int n)
{
	int	i;

	i = 1;
	if (a->n != n)
		return (0);
	while (i < n)
	{
		if (a->arr[i] < a->arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int n, char **arr)
{
	t_stack	a;
	t_stack	b;
	int		len;
	char	*s;

	if (n == 1 || ft_parse(n, arr, &a, &b))
		return (1);
	len = a.n;
	s = get_next_line(0);
	while (s)
	{
		if (ft_check_part_one(&a, &b, s) == 0 && fr_int(&a.arr))
		{	
			write(1, "Error\n", 6);
			free(s);
			free(b.arr);
			return (1);
		}
		free(s);
		s = get_next_line(0);
	}
	if (ft_sorted(&a, len) && fr_int(&a.arr) && fr_int(&b.arr))
		write(1, "OK\n", 3);
	else if (fr_int(&a.arr) && fr_int(&b.arr))
		write(1, "KO\n", 3);
}
