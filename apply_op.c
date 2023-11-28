/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:32:49 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/21 21:00:06 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if ((unsigned char) str1[i] != (unsigned char) str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}

void	apply_op(t_stack	**s, char *op)
{
	if (!ft_strcmp(op, "ra"))
	{
		write (1, "ra\n", 3);
		rotate(s, NULL, op);
	}
	else if (!ft_strcmp(op, "rra"))
	{
		write (1, "rra\n", 4);
		rotate_r(s, NULL, op);
	}
	else if (!ft_strcmp(op, "sa"))
	{
		write (1, "sa\n", 3);
		sx(s, NULL, op);
	}
}
