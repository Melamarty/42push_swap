/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:27 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/21 20:52:12 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rx(t_stack **s)
{
	t_stack	*tmp;
	int		top;

	if (!s || !(*s)->next)
		return ;
	tmp = *s;
	top = tmp->val;
	while (tmp->next)
	{
		tmp->val = tmp->next->val;
		tmp = tmp->next;
	}
	tmp->val = top;
}

void	rotate(t_stack **a, t_stack **b, char *op)
{
	if (op[0] == 'r' && op[1] == 'a')
		rx(a);
	if (op[0] == 'r' && op[1] == 'b')
		rx(b);
	if (op[0] == 'r' && op[1] == 'r')
	{
		rx(a);
		rx(b);
	}
}

static void	rrx(t_stack **s)
{
	t_stack	*tmp;
	int		v1;
	int		v2;

	if (!s || !(*s)->next)
		return ;
	tmp = (*s)->next;
	v1 = (*s)->val;
	while (tmp)
	{
		v2 = tmp->val;
		tmp->val = v1;
		v1 = v2;
		tmp = tmp->next;
	}
	(*s)->val = v1;
}

void	rotate_r(t_stack **a, t_stack **b, char *op)
{
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a')
		rrx(a);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b')
		rrx(b);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r')
	{
		rrx(a);
		rrx(b);
	}
}
