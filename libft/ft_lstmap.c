/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:15:40 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:55:28 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (!f || !lst || !(new = f(lst)))
		return (NULL);
	head = new;
	while ((lst = lst->next))
	{
		if (!(new->next = f(lst)))
		{
			free(new);
			return (NULL);
		}
		new = new->next;
	}
	return (head);
}
