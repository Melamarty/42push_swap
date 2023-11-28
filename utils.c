/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:39:14 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:43:59 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	list_size(t_stack *s)
{
	int	len;

	len = 0;
	while (s)
	{
		s = s->next;
		len++;
	}
	return (len);
}

int	list_average(t_stack *a)
{
	int	total;
	int	count;

	total = 0;
	count = 0;
	while (a)
	{
		total += a->val;
		count++;
		a = a->next;
	}
	if (!count)
		return (0);
	return (total / count);
}
