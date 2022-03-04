/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:16:19 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/04 14:18:44 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	while (ft_isspace((int)nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	value = 0;
	while (ft_isdigit((int)nptr[i]))
	{
		value = value * 10 + (nptr[i] - '0');
		i++;
	}
	return ((long)value * sign);
}
