/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:40:49 by pnoronha          #+#    #+#             */
/*   Updated: 2021/07/03 01:27:57 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t		len;

	len = 0;
	while (*s && maxlen--)
	{
		len++;
		s--;
	}
	return (len);
}
