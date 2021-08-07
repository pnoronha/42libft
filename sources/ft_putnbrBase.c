/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrBase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:19:26 by pnoronha          #+#    #+#             */
/*   Updated: 2021/08/05 15:46:05 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define VALID_BASE 1
#define INVALID_BASE 0

static int	checkBase(const char *base)
{
	int	i;
	int	j;

	if (!base)
		return (INVALID_BASE);
	if (base[0] == '\0' || base[1] == '\0')
		return (INVALID_BASE);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (INVALID_BASE);
			j++;
		}
		i++;
	}
	return (VALID_BASE);
}

int	ft_putnbrBase(unsigned long nbr, const char *base)
{
	unsigned int	baseLen;
	int	nbrLen;

	if (!checkBase(base))
		return (0);
	baseLen = ft_strlen(base);
	nbrLen = 0;
	if (nbr < baseLen)
	{
		ft_putchar(base[nbr]);
		nbrLen++;
	}
	else
	{
		nbrLen += ft_putnbrBase(nbr / baseLen, base);
		nbrLen += ft_putnbrBase(nbr % baseLen, base);
	}
	return (nbrLen);
}
