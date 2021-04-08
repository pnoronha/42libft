/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:16:02 by pnoronha          #+#    #+#             */
/*   Updated: 2021/04/08 18:42:37 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	str_lengh;
	size_t	i;

	str_lengh = ft_strlen(s);
	if (!s)
		return (NULL);
	if (str_lengh <= start)
		len = 0;
	else if (len > (str_lengh - (str_lengh - start)))
		len = (str_lengh - start);
	sub_str = malloc(sizeof(char) * (len));
	if (!sub_str)
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
