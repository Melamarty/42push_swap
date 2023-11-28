/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:19:16 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/22 01:26:34 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		sb;
	int		sa;

	tmp = *b;
	sb = list_size(*b);
	sa = list_size(*a);
	while (tmp)
	{
		tmp->cb = tmp->ind;
		if (tmp->ind > sb / 2)
			tmp->cb = tmp->ind - sb;
		tmp->ca = tmp->tg;
		if (tmp->tg > sa / 2)
			tmp->ca = tmp->tg - sa;
		tmp = tmp->next;
	}
}

void	reset_inds(t_stack **s)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *s;
	while (tmp)
	{
		tmp->ind = i++;
		tmp = tmp->next;
	}
}
