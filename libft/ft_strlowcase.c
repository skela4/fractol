/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:29:04 by aahizi-e          #+#    #+#             */
/*   Updated: 2018/11/24 20:39:24 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(const char *s)
{
	char	*p;
	char	*str;

	str = (char *)s;
	p = str;
	while (*str)
	{
		if (ft_isalpha(*str) && ft_isupper(*str))
			*str = (char)ft_tolower(*str);
		str++;
	}
	return (p);
}
