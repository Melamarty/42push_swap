/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:50:27 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/21 21:01:32 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	list_max(t_stack *s)
{
	int	max;

	max = s->val;
	s = s->next;
	while (s)
	{
		if (s->val > max)
			max = s->val;
		s = s->next;
	}
	return (max);
}

int	list_min(t_stack *s)
{
	int	min;

	min = s->val;
	s = s->next;
	while (s)
	{
		if (s->val < min)
			min = s->val;
		s = s->next;
	}
	return (min);
}
