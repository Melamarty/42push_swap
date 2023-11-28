/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:13 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/22 01:45:58 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_stack **s)
{
	int	tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = (*s)->val;
	(*s)->val = (*s)->next->val;
	(*s)->next->val = tmp;
}

void	sx(t_stack **a, t_stack **b, char *op)
{
	if (op[0] == 's' && op[1] == 'a')
		swap(a);
	if (op[0] == 's' && op[1] == 'b')
		swap(b);
	if (op[0] == 's' && op[1] == 's' && list_size(*a) > 1 && list_size(*b) > 1)
	{
		swap(a);
		swap(b);
	}
}

static void	push_op(t_stack **a, t_stack **b)
{
	int		topval;
	t_stack	*tmp;

	if (!*b)
		return ;
	topval = pop(b);
	push(a, topval);
	tmp = (*a)->next;
	while (tmp)
	{
		tmp->ind = tmp->ind + 1;
		tmp = tmp->next;
	}
}

void	px(t_stack **a, t_stack **b, char *op)
{
	if (op[0] == 'p' && op[1] == 'a')
		push_op(a, b);
	if (op[0] == 'p' && op[1] == 'b')
		push_op(b, a);
}
