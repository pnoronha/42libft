/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:41:50 by pnoronha          #+#    #+#             */
/*   Updated: 2021/03/31 00:44:28 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_str(char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int				i;
	unsigned int	str_size;
	char			*trimmed_str;
	char			*str_start;
	char			*str_end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_char_in_str(s1[i], set))
		i++;
	str_start = (char *)&s1[i];
	if ((i = ft_strlen(s1) - 1) != -1)
		while (i >= 0 && ft_char_in_str(s1[i], set))
			i--;
	str_end = (char *)&s1[i];
	if (!*s1 || str_end == str_start)
		str_size = 2;
	else
		str_size = str_end - str_start + 2;
	if (!(trimmed_str = malloc(sizeof(char) * str_size)))
		return (NULL);
	ft_strlcpy(trimmed_str, str_start, str_size);
	return (trimmed_str);
}
