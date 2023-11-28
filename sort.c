/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:38:16 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:27:15 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	gap_a(t_stack **a, int ind, int type)
{
	int	size;

	size = list_size(*a);
	if (type)
	{
		while (ind > 0)
		{
			write(1, "ra\n", 3);
			rotate(a, NULL, "ra");
			ind--;
		}
	}
	else
	{
		while (ind < size)
		{
			write(1, "rra\n", 4);
			rotate_r(a, NULL, "rra");
			ind++;
		}
	}
}

void	gap_b(t_stack **b, int ind, int type)
{
	int	size;

	size = list_size(*b);
	if (type)
	{
		while (ind > 0)
		{
			write(1, "rb\n", 3);
			rotate(NULL, b, "rb");
			ind--;
		}
	}
	else
	{
		while (ind < size)
		{
			write(1, "rrb\n", 4);
			rotate_r(NULL, b, "rrb");
			ind++;
		}
	}
}

static void	gap_two(t_stack **a, t_stack **b, t_c_ind *ind, int size)
{
	if (ind->a > size / 2)
	{
		while (size - ind->a > 0)
		{
			rotate_r(a, b, "rrr");
			write(1, "rrr\n", 4);
			ind->a++;
		}
	}
	else
	{
		while (ind->a > 0)
		{
			rotate(a, b, "rr");
			write(1, "rr\n", 3);
			ind->a--;
		}
	}
}

void	gap_cheaper(t_stack **s1, t_stack **s2, t_c_ind *ind)
{
	int		size;

	size = list_size(*s1);
	if (!ind->a && !ind->b)
		return ;
	if (
		(ind->a == ind->b && ind->a < size / 2 && ind->b < size / 2)
		|| (size - ind->a == list_size(*s2) - ind->b && ind->b
			&& ind->b > size / 2)
	)
	{
		gap_two(s1, s2, ind, size);
		return ;
	}
	if (ind->a && ind->a > 0 && ind->a <= size / 2)
		gap_a(s1, ind->a, 1);
	else if (ind->a && ind->a > 0 && ind->a > size / 2)
		gap_a(s1, ind->a, 0);
	if (ind->b && ind->b > 0 && ind->b <= list_size(*s2) / 2)
		gap_b(s2, ind->b, 1);
	else if (ind->b > 0 && ind->b > list_size(*s2) / 2)
		gap_b(s2, ind->b, 0);
}

void	sort(t_stack *a, t_stack *b)
{
	int	average;
	int	size;

	average = list_average(a);
	size = list_size(a);
	while (size > 0 && list_size(a) > 3)
	{
		if (a->val <= average)
		{
			px(&a, &b, "pb");
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(&a, &b, "ra");
			write(1, "ra\n", 3);
		}
		size--;
	}
	while (list_size(a) > 3)
	{
		px(&a, &b, "pb");
		write(1, "pb\n", 3);
	}
	to_a(&a, &b);
}
