/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheaper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:18:22 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/21 21:00:30 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_ind(t_stack *s, int val)
{
	int	ind;

	ind = 0;
	while (s && s->val != val)
	{
		ind++;
		s = s->next;
	}
	return (ind);
}

int	get_target(t_stack *a, int val)
{
	int	tmp;
	int	tg;

	tmp = INT_MAX;
	if (val > list_max(a))
		return (get_ind(a, list_min(a)));
	while (a)
	{
		if (a->val > val && a->val < tmp)
		{
			tmp = a->val;
			tg = a->ind;
		}
		a = a->next;
	}
	return (tg);
}

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		tmp->tg = get_target(*a, tmp->val);
		tmp = tmp->next;
	}
}

t_c_ind	min_cost(t_stack *b)
{
	t_c_ind	inds;
	int		min;
	int		tmp;

	tmp = INT_MAX;
	while (b)
	{
		min = (b->cb > 0) * b->cb + (b->cb < 0) * (-b->cb);
		min += (b->ca > 0) * b->ca + (b->ca < 0) * (-b->ca);
		if (min < tmp)
		{
			inds.a = b->tg;
			inds.b = b->ind;
			tmp = min;
		}
		b = b->next;
	}
	return (inds);
}

void	send_to_a(t_stack **a, t_stack **b)
{
	t_c_ind	inds;

	while (list_size(*b) > 0)
	{
		reset_inds(a);
		reset_inds(b);
		set_target(a, b);
		set_cost(a, b);
		inds = min_cost(*b);
		gap_cheaper(a, b, &inds);
		write(1, "pa\n", 3);
		px(a, b, "pa");
	}
}
