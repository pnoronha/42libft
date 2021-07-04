/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:09:23 by pnoronha          #+#    #+#             */
/*   Updated: 2021/04/15 18:09:23 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;
	t_list	*temp;

	clear = *lst;
	while (clear)
	{
		temp = clear->next;
		ft_lstdelone(clear, del);
		clear = temp;
	}
	*lst = NULL;
}
