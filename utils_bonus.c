/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:37 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:42:50 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long	ft_atoi(const char *str)
{
	int			i;
	int long	res;
	int			s;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	s = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * s);
}

int	is_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	print_err(int type)
{
	if (type == 0 || type == 1)
		write(2, "Error\n", 6);
	return (1);
}

int	is_sorted(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (tmp->next)
	{
		if (tmp->val >= tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
