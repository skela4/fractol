/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 05:01:42 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:49:16 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strtrim_reverse(char *s, char *head, int size)
{
	char	*tail;

	tail = s + size - 1;
	while (*tail == ' ' || *tail == '\t' || *tail == '\n')
		tail--;
	return (ft_strsub(head, 0, (tail + 1) - head));
}

char			*ft_strtrim(char const *s)
{
	char	*h;

	if (!(h = ((char *)s)))
		return (NULL);
	while (*h == ' ' || *h == '\t' || *h == '\n')
		h++;
	if (!*h)
		return (ft_strdup(h));
	return (ft_strtrim_reverse((char *)s, h, ft_strlen(s)));
}
