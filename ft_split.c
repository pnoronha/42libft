/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:47:50 by pnoronha          #+#    #+#             */
/*   Updated: 2021/04/22 13:26:37 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static void	*ft_free_array(char **strs_array, int i)
{
	while (i >= 0)
	{
		free(strs_array[i--]);
	}
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**strs_array;
	int		nb_words;
	int		i;

	if (!s)
		return (NULL);
	nb_words = ft_wordcnt(s, c);
	strs_array = malloc(sizeof(char *) * (nb_words + 1));
	if (!strs_array)
		return (NULL);
	i = 0;
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		strs_array[i] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!strs_array[i])
			return (ft_free_array(strs_array, i));
		s += ft_wordlen(s, c);
		i++;
	}
	strs_array[i] = NULL;
	return (strs_array);
}
