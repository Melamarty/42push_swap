/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:16:38 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:50:01 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	is_nbs(char **nbs)
{
	int	i;

	i = 1;
	while (nbs[i])
	{
		if (!is_nb(nbs[i]))
			return (0);
		i++;
	}
	return (1);
}

void	execute(t_stack **a, t_stack **b, char *op)
{
	if (list_size(*a) < 1 && list_size(*b) < 1)
		return ;
	if (op[0] == 's')
		sx(a, b, op);
	if (op[0] == 'p')
		px(a, b, op);
	if (op[0] == 'r' && op[1] == 'r' && op[3])
		rotate_r(a, b, op);
	else
		rotate(a, b, op);
}

static	void	execute_ops(t_stack **a, t_stack **b)
{
	char	*line;

	if (!a)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	line = get_next_line(0);
	while (line)
	{
		if (!is_op(line))
		{
			write(2, "Error\n", 6);
			ft_lstclear(a);
			ft_lstclear(b);
			exit (0);
		}
		execute(a, b, line);
		free (line);
		line = get_next_line(0);
	}
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
		ft_lstclear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	execute_ops(&a, &b);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	return (0);
}
