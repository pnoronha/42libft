/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:41:50 by pnoronha          #+#    #+#             */
/*   Updated: 2021/04/13 22:12:16 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_str (const char str, const char *set)
{
	while (*set)
	{
		if (str == *set)
			return (1);
		set++;
	}
	return (0);
}

int	ft_index_to_skip(const char *str, const char *set, int flag)
{
	int	i;

	if (flag == 1)
	{
		i = 0;
		while (str[i] && ft_char_in_str(str[i], set))
			i++;
	}
	if (flag == 2)
	{
		i = ft_strlen(str) - 1;
		if (i != -1)
			while (i >= 0 && ft_char_in_str(str[i], set))
				i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	str_size;
	char			*trimmed_str;
	char			*str_start;
	char			*str_end;

	if (!s1 || !set)
		return (NULL);
	str_start = (char *)&s1[ft_index_to_skip(s1, set, 1)];
	if (s1[ft_index_to_skip(s1, set, 1)] == '\0')
	{
		str_size = 1;
		trimmed_str = malloc(sizeof(char) * 1);
	}
	else
	{
		str_end = (char *)&s1[ft_index_to_skip(s1, set, 2)];
		str_size = str_end - str_start + 2;
		trimmed_str = malloc(sizeof(char) * str_size);
	}
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, str_start, str_size);
	return (trimmed_str);
}
