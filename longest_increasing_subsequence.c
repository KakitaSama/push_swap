/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:41:51 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:41 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pre_longest_inc(int **dp, int **last, int n)
{
	int	i;

	i = 0;
	*dp = (int *)malloc(n * sizeof(int));
	if (*dp == NULL)
		return (0);
	*last = (int *)malloc(n * sizeof(int));
	if (*last == NULL)
	{
		free(*dp);
		return (0);
	}
	while (i < n)
	{
		(*dp)[i] = 1;
		(*last)[i] = -1;
		i++;
	}
	return (1);
}

int	ft_lis_part_one(int *arr, int *dp, int *last, int n)
{
	int	i;
	int	idx;
	int	j;

	i = 1;
	idx = 0;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				last[i] = j;
			}
			j++;
		}
		if (dp[i] > dp[idx])
			idx = i;
		i++;
	}
	return (idx);
}

int	*longest_increasing_subsequence(int *arr, int n, int *lis_length)
{
	int	*dp;
	int	*last;
	int	idx;
	int	j;

	if (!pre_longest_inc(&dp, &last, n))
	{
		*lis_length = 0;
		return (NULL);
	}
	idx = ft_lis_part_one(arr, dp, last, n);
	*lis_length = dp[idx];
	j = dp[idx] - 1;
	free(dp);
	dp = (int *)malloc((j + 1) * sizeof(int));
	while (dp && idx >= 0)
	{
		dp[j] = arr[idx];
		if (last[idx] == -1)
			break ;
		j--;
		idx = last[idx];
	}
	free(last);
	return (dp);
}
