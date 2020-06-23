/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:40:00 by aahizi-e          #+#    #+#             */
/*   Updated: 2018/11/24 20:48:02 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	char	c1;
	char	c2;

	while (*s1 || *s2)
		if (*(s1++) != *(s2++))
		{
			c1 = (char)*(s1 - 1);
			c2 = (char)*(s2 - 1);
			if (ft_isalpha((int)c1) && ft_isupper((int)c1))
				c1 = (char)ft_tolower((int)c1);
			if (ft_isalpha((int)c2) && ft_isupper((int)c2))
				c2 = (char)ft_tolower((int)c2);
			return ((unsigned char)c1 - (unsigned char)c2);
		}
	return (0);
}
