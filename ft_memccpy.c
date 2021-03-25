/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:45:10 by pnoronha          #+#    #+#             */
/*   Updated: 2021/03/25 21:48:47 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr_src;
	char	*ptr_dst;
	size_t	i;

	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if ((unsigned char)ptr_src[i] == (unsigned char)c)
			return ((char *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
