/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:33 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:41:07 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stack **s, int val)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	tmp->val = val;
	tmp->next = *s;
	*s = tmp;
}

int	pop(t_stack **s)
{
	t_stack	*top;
	int		val;

	if (!s)
		return (-1);
	top = *s;
	val = top->val;
	*s = top->next;
	free(top);
	top = NULL;
	return (val);
}
