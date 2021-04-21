/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:13:36 by pnoronha          #+#    #+#             */
/*   Updated: 2021/04/03 17:13:36 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_item;

	list_item = (t_list *) malloc(sizeof(t_list));
	if (!list_item)
		return (NULL);
	list_item->content = content;
	list_item->next = NULL;
	return (list_item);
}
