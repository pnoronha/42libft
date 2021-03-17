/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:49:55 by pnoronha          #+#    #+#             */
/*   Updated: 2021/03/15 20:39:22 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ptr_s1 && *ptr_s2 && n--)
	{
		if (*ptr_s1 != *ptr_s2)
		{
			return (*ptr_s1 - *ptr_s2);
		}
		if (n)
		{
			ptr_s1++;
			ptr_s2++;
		}
	}
	return (0);
}
