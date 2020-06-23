/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:46:17 by aahizi-e          #+#    #+#             */
/*   Updated: 2018/11/24 20:54:43 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	char				c1;
	char				c2;
	unsigned	int		i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			c1 = (char)s1[i];
			c2 = (char)s2[i];
			if (ft_isalpha((int)c1) && ft_isupper((int)c1))
				c1 = (char)ft_tolower((int)c1);
			if (ft_isalpha((int)c2) && ft_isupper((int)c2))
				c2 = (char)ft_tolower((int)c2);
			return ((unsigned char)c1 - (unsigned char)c2);
		}
		i++;
	}
	return (0);
}
