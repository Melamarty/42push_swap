/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cheaper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:50:21 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/21 21:01:25 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ops_count(t_c_ind *ind, int len1, int len2)
{
	int	count;

	count = 0;
	if (ind->a > len1 / 2)
		count += len1 - ind->a;
	else
		count += ind->a;
	if (ind->b > len2 / 2)
		count += len2 - ind->b;
	else
		count += ind->b;
	if (len1 - ind->a == len2 - ind->b)
		return (count / 2);
	return (count);
}

int	is_cheaper(t_c_ind *ind1, t_c_ind *ind2, int len1, int len2)
{
	if (ops_count(ind1, len1, len2) < ops_count(ind2, len1, len2))
		return (1);
	return (0);
}
