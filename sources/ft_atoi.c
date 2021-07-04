/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:16:25 by pnoronha          #+#    #+#             */
/*   Updated: 2021/07/03 01:27:14 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		value;

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
	return ((int)value * sign);
}
