/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:43:29 by pnoronha          #+#    #+#             */
/*   Updated: 2021/03/17 18:47:33 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_malloc_error(char **arr_str)
{
	unsigned int	i;

	i = 0;
	while (arr_str[i])
	{
		free(arr_str[i]);
		i++;
	}
	free(arr_str);
	return (NULL);
}

static void		ft_find_next_str(char **str, unsigned int *next_str_index,
char c)
{
	unsigned int	i;

	*str += *next_str_index;
	next_str_index = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*next_str_index)++;
		i++;
	}
}

static int		ft_nbr_strs(const char *s, char c)
{
	unsigned int	i;
	unsigned int	nbr_strs;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nbr_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nbr_strs++;
	return (nbr_strs);
}

char		**ft_split(const char *s, char c)
{
	char			**arr_str;
	char			*str;
	unsigned int	next_str_index;
	unsigned int	nbr_strs;
	unsigned int 	i;

	if (!s)
		return (NULL);
	nbr_strs = ft_nbr_strs(s, c);
	if (!(arr_str = (char **)malloc(sizeof(char *) * (nbr_strs + 1))))
		return (NULL);
	i = 0;
	str = (char *)s;
	next_str_index = 0;
	while (i < nbr_strs)
	{
		ft_find_next_str(&str, &next_str_index, c);
		if (!(arr_str[i] = (char *)malloc(sizeof(char) * (next_str_index + 1))))
			return (ft_malloc_error(arr_str));
		ft_strlcpy(arr_str[i], str, next_str_index + 1);
		i++;
	}
	arr_str[i] = NULL;
	return (arr_str);
}
