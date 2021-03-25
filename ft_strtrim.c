/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:41:50 by pnoronha          #+#    #+#             */
/*   Updated: 2021/03/25 13:47:12 by pnoronha         ###   ########.fr       */
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
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed_str;

	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_char_in_str(s1[start], set))
		start++;
	while (end > start && ft_char_in_str(s1[end], set))
		end--;
	if (!(trimmed_str = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (start < end)
		trimmed_str[i++] = s1[start++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
