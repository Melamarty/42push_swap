/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:50:03 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/21 23:54:42 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*get_word(const char *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	*ft_free_s(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**spl;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	spl = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (spl == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			spl[i++] = get_word(s, c);
			if (!spl[i - 1])
				return (ft_free_s(spl, i - 1));
			while (*s && *s != c)
				s++;
		}
	}
	spl[i] = NULL;
	return (spl);
}
