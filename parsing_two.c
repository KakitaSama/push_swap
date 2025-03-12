/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:24:17 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 23:16:37 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlz(char *s)
{
	int	i;
	int	len;
	int	k;

	i = 0;
	len = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] >= '1' && s[i] <= '9')
			k += 2;
		if (k >= 2 || (s[i] != '0'))
			len++;
		else if (s[i] == '0' && k == 0)
		{
			len++;
			k++;
		}
		i++;
	}
	return (len);
}

int	fr_int(int **v)
{
	free(*v);
	*v = NULL;
	return (1);
}

char	**ft_parsing_part_one(char **arr, int n, int *p, int *i)
{
	char	*ans0;
	char	**s;
	char	*tmp;

	ans0 = ft_strdup("");
	*i = 1;
	*p = 1;
	while (*i < n)
	{
		tmp = ans0;
		ans0 = ft_strjoin(ans0, arr[*i]);
		if (ft_strlen(arr[*i]) == 0)
			*p = 0;
		free(tmp);
		tmp = ans0;
		ans0 = ft_strjoin(ans0, " ");
		free(tmp);
		(*i)++;
	}
	s = ft_split(ans0, ' ');
	*i = 0;
	free(ans0);
	return (s);
}

int	ft_parse(int n, char **arr, t_stack *a, t_stack *b)
{
	int		i;
	char	**s;
	int		*vector;
	int		p;

	s = ft_parsing_part_one(arr, n, &p, &i);
	while (s && s[i])
		i++;
	n = i;
	vector = ft_check(s, i);
	while (s && i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	if (p == 0 && fr_int(&vector))
		vector = NULL;
	if (vector == NULL || ft_init(vector, n, a, b))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
