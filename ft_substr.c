/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:16:02 by pnoronha          #+#    #+#             */
/*   Updated: 2021/03/30 16:44:06 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	if (!(sub_str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
