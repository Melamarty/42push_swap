/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:16:56 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/28 19:32:25 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_not_nb(char *nb)
{
	if (*nb == '-' || *nb == '+')
		nb++;
	if (*nb > '9' || *nb < '0')
		return (1);
	while (*nb && *nb != ' ')
	{
		if (*nb > '9' || *nb < '0')
			return (1);
		nb++;
	}
	return (0);
}

void	ft_free(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free (spl[i]);
		spl[i] = NULL;
		i++;
	}
}

int	check_one(char *nbs)
{
	int		i;
	char	**spl;

	while (*nbs == ' ')
		nbs++;
	if (!*nbs)
		return (0);
	spl = ft_split(nbs, ' ');
	i = 0;
	while (spl[i])
	{
		if (is_not_nb(spl[i]))
		{
			ft_free(spl);
			free (spl);
			return (0);
		}
		i++;
	}
	ft_free(spl);
	free (spl);
	return (1);
}

int	check_args(char **nbs, int ac)
{
	int	i;

	if (ac == 2)
		return (check_one(nbs[1]));
	i = 1;
	while (i < ac)
	{
		if (!check_one(nbs[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(char **av, int ac)
{
	char	**spl;
	int		i;

	while (ac > 1)
	{
		ac--;
		i = -1;
		spl = ft_split(av[ac], ' ');
		while (spl[++i])
		{
			if (ft_atoi(spl[i]) > INT_MAX || ft_atoi(spl[i]) < INT_MIN)
			{
				ft_free(spl);
				free (spl);
				return (0);
			}
		}
		ft_free(spl);
		free (spl);
	}
	return (1);
}
