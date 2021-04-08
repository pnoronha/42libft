/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:47:50 by pnoronha          #+#    #+#             */
/*   Updated: 2021/04/05 17:52:17 by pnoronha         ###   ########.fr       */
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

static void	*ft_free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i--]);
	}
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		nb_words;
	int		i;

	if (!s)
		return (NULL);
	nb_words = ft_wordcnt(s, c);
	tab = malloc(sizeof(char **) * (nb_words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!tab[i])
			return (ft_free_tab(tab, i));
		s += ft_wordlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
