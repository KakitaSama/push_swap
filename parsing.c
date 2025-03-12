/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:11:40 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 23:16:38 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_change(int *p)
{
	*p = -1;
	return (1);
}

void	*ft_calloc(int n, int k)
{
	long long	size;
	int			*p;
	long long	i;

	i = 0;
	size = n * 1ll * k;
	p = malloc(size);
	if (p == NULL)
		return (p);
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
	size++;
	return (p);
}

int	ft_dup(int *arr, int k)
{
	int	i;
	int	j;

	i = 0;
	if (arr == NULL)
		return (1);
	while (i < k)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_char(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	*ft_check(char **arr, int k)
{
	int			i;
	long long	p;
	int			*vector;

	if (k == 0)
		return (NULL);
	vector = malloc(k * sizeof(int));
	i = 0;
	while (i < k && vector)
	{
		if ((ft_strlz(arr[i]) > 13 || ft_check_char(arr[i])) && ft_change(&i))
			break ;
		p = ft_atoi(arr[i]);
		if ((p > 2147483647LL || p < -2147483648LL) && ft_change(&i))
			break ;
		vector[i] = p;
		i++;
	}
	if (i == -1 || ft_dup(vector, k))
	{
		free(vector);
		vector = NULL;
	}
	return (vector);
}
