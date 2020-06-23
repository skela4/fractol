/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 04:47:57 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:56:57 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelete(t_list **head_list, t_list *lst)
{
	t_list	*tmp;
	t_list	*delete;

	tmp = *head_list;
	while (tmp->next && ft_strcmp(tmp->next->content, lst->content))
		tmp = tmp->next;
	delete = tmp->next;
	tmp->next = delete->next;
	free(delete->content);
	free(delete);
}
