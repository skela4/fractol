/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 04:47:57 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 22:43:32 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	t_list	*add_link(t_list *list, char *str, size_t size)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!str)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
	}
	else
	{
		tmp->content = ft_strdup(str);
		tmp->content_size = size;
		tmp->next = list;
	}
	return (tmp);
}

t_list			*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*list;

	list = NULL;
	list = add_link(list, (char *)content, content_size);
	return (list);
}
