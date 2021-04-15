/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:33:19 by pnoronha          #+#    #+#             */
/*   Updated: 2021/04/14 21:33:19 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if(lst == NULL)
		return (NULL);
	while(lst)
	{
		if(lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
