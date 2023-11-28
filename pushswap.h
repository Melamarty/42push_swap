/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:28:42 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:41:54 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	int				ind;
	struct s_stack	*next;
	int				tg;
	int				cb;
	int				ca;
}	t_stack;

typedef struct s_c_ind
{
	int	a;
	int	b;
}	t_c_ind;

int		check_overflow(char **av, int ac);
long	ft_atoi(const char *str);
int		is_nb(char *str);
int		is_sorted(t_stack *s);
void	push(t_stack **s, int val);
int		pop(t_stack **s);
int		print_err(int type);
void	sx(t_stack **a, t_stack **b, char *op);
void	px(t_stack **a, t_stack **b, char *op);
void	rotate(t_stack **a, t_stack **b, char *op);
void	rotate_r(t_stack **a, t_stack **b, char *op);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		list_size(t_stack *s);
void	apply_op(t_stack	**s, char *op);
int		list_max(t_stack *s);
int		list_min(t_stack *s);
int		is_cheaper(t_c_ind *ind1, t_c_ind *ind2, int len1, int len2);
t_stack	*parse_args(char **nbs, int ac);
int		check_args(char **nbs, int ac);
int		repet(t_stack *s);
int		get_ind(t_stack *s, int val);
int		list_average(t_stack *a);
void	sort(t_stack *a, t_stack *b);
void	sort_three(t_stack **s);
void	sort_rest(t_stack **s, int size);
int		all_is_big(t_stack *a, int average);
void	gap_cheaper(t_stack **s1, t_stack **s2, t_c_ind *ind);
void	send_to_a(t_stack **a, t_stack **b);
char	**ft_split(const char *s, char c);
void	to_a(t_stack **a, t_stack **b);
void	set_cost(t_stack **a, t_stack **b);
void	reset_inds(t_stack **s);
void	ft_lstclear(t_stack **lst);
int		is_op(char *op);
void	ft_free(char **spl);

#endif