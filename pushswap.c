/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:51:02 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:54:16 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (list_size(a) <= 3)
	{
		sort_three(&a);
		ft_lstclear(&a);
	}
	else
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2 || !check_args(av, ac) || !check_overflow(av, ac))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	a = parse_args(av, ac);
	if (repet(a))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&a);
		return (1);
	}
	if (is_sorted(a) || list_size(a) <= 1)
	{
		ft_lstclear(&a);
		return (0);
	}
	push_swap(a, b);
}
