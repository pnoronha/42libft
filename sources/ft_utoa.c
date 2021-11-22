/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:11:55 by pnoronha          #+#    #+#             */
/*   Updated: 2021/11/22 19:13:15 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				count;
	unsigned int	nbr;

	if (n == 0)
		return (ft_strdup("0"));
	count = ft_unsignedlen(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (--count >= 0)
	{
		nbr = n % 10;
		str[count] = nbr + '0';
		n /= 10;
	}
	return (str);
}
