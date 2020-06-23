/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:14:07 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:53:19 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*tmp;

	if (alst && del && (head = *alst))
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			ft_lstdelone(&tmp, del);
		}
		head = NULL;
	}
}
