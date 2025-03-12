/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jazo <sel-jazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:17:41 by sel-jazo          #+#    #+#             */
/*   Updated: 2025/01/28 23:17:28 by sel-jazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct t_stack
{
	int	id;
	int	n;
	int	*arr;
	int	side;
}	t_stack;

int			fr_int(int **v);
int			ft_fr(char **s);
char		*get_next_line(int fd);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
int			ft_search(char *buf);
int			ft_strlen(char *s);
char		*get_next_line(int fd);
int			ft_prework(char **buf, char **str, char **ans, char *tmp);
int			ft_res(char **buf, char **str, char **ans, int p);
int			ft_looping(char **buf, char **str, char **ans, int fd);
int			ft_dup(int *arr, int k);
void		ft_add_back(t_stack *b, t_stack *a);
int			ft_parse(int n, char **arr, t_stack *a, t_stack *b);
int			ft_check_char(char *str);
long long	ft_atoi(const char *str);
int			*ft_check(char **arr, int k);
void		ft_swap(t_stack *a, int p);
void		ft_rot(t_stack *a, int p);
void		ft_rrot(t_stack *a, int p);
void		ft_push(t_stack *a, t_stack *b, int p);
void		*ft_calloc(int n, int k);
long long	min(long long a, long long b);
long long	max(long long a, long long b);
int			ft_init(int	*vector, int n, t_stack *a, t_stack *b);
long long	ft_abs(long long ans);
int			ft_calc(t_stack *a, t_stack *b, int i, int j);
void		ft_sort_elem(t_stack *a, t_stack *b, int i, int j);
int			ft_sort(t_stack *a, t_stack *b);
int			ft_sort_manual(t_stack *a);
char		**ft_split(char const *str, char c);
long long	max(long long a, long long b);
long long	min(long long a, long long b);
void		ft_sort_three_part_two(t_stack *a, int max0);
void		ft_sub_sort_elem_one(t_stack *a, t_stack *b, int i, int j);
void		ft_sub_sort_elem_two(t_stack *a, t_stack *b, int i, int j);
void		ft_sub_sort_elem_three(t_stack *a, t_stack *b, int i, int j);
void		ft_sub_sort_elem_four(t_stack *a, t_stack *b, int i, int j);
void		ft_two_ft_root(t_stack *a, t_stack *b);
void		ft_sort_loop(t_stack *a, t_stack *b, int *id0, int *id1);
int			ft_sort_loop_loop(t_stack *a, t_stack *b, int i);
int			ft_change(int *p);
int			ft_check_part_one(t_stack *a, t_stack *b, char *s);
int			ft_check_part_two(t_stack *a, t_stack *b, char *s);
int			ft_check_part_three(t_stack *a, t_stack *b, char *s);
int			cmp(char *s, char *t);
int			*longest_increasing_subsequence(int *arr, int n, int *lis_length);
int			ft_lis_part_one(int *arr, int *dp, int *last, int n);
int			pre_longest_inc(int **dp, int **last, int n);
int			ft_strlz(char *s);
#endif
