/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 04:42:34 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 18:39:21 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_cword(char *s, char d)
{
	int		word;

	word = 0;
	while (*s)
	{
		while (*s && *s == d)
			s++;
		while (*s && *s != d)
			s++;
		if (*(s - 1) != d)
			word++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*t;
	char	**r;
	int		w;
	int		j;

	if (!s)
		return (NULL);
	w = ft_cword((char *)s, c);
	if (!(r = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	j = w;
	while (j && j--)
	{
		while (*s == c && *s)
			s++;
		t = (char *)s;
		while (*s != c && *s)
			s++;
		if (!(*(r)++ = ft_strsub((char *)t, 0, s - t)))
			return (NULL);
	}
	*(r) = 0;
	return (r - w);
}
