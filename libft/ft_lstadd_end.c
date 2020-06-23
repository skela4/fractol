/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 04:47:57 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:57:02 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **head_list, t_list *new_list)
{
	t_list	*last;

	if (head_list && !(*head_list))
		*head_list = new_list;
	else if (head_list && *head_list && (last = *head_list))
	{
		while (last->next)
			last = last->next;
		last->next = new_list;
		new_list->next = NULL;
	}
}
