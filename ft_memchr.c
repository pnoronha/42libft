/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:37:34 by pnoronha          #+#    #+#             */
/*   Updated: 2021/03/11 19:46:34 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr_s;
	size_t		i;

	ptr_s = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == c)
		{
			return ((void *)&ptr_s[i]);
		}
		i++;
	}
	return (NULL);
}
