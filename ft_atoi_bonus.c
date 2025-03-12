/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:11:51 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:48:04 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long long	min(long long a, long long b)
{
	if (a <= b)
		return (a);
	return (b);
}

long long	max(long long a, long long b)
{
	if (a <= b)
		return (b);
	return (a);
}

static long long	ft_sign(const char *str, long long *p)
{
	int	res;
	int	i;

	i = *p;
	res = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			res = -1;
		i++;
	}
	*p = i;
	return (res);
}

static long long	ft_cal(const char *str, long long i, long long ng)
{
	long long	a;
	long long	ans;
	long long	c;

	a = 9223372036854775807ll;
	ans = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		c = str[i] - '0';
		if (ng == 1 && (a - c) / 10 < ans)
			return (-1);
		if (ng == -1 && (a - c) / 10 < ans)
			return (0);
		ans = ans * 10ll + c;
		i++;
	}
	return (ans);
}

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	ng;
	long long	ans;
	long long	final_ans;

	i = 0;
	ng = 0;
	ans = 0;
	final_ans = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	ng = ft_sign(str, &i);
	ans = ft_cal(str, i, ng);
	ans = ng * ans;
	final_ans = ans;
	return (final_ans);
}
