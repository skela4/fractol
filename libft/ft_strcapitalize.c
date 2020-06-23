/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:39:15 by aahizi-e          #+#    #+#             */
/*   Updated: 2018/11/24 18:36:50 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(const char *s)
{
	char	*c;
	char	*str;

	c = (char *)s;
	str = c;
	while (*c)
	{
		while (*c && (ft_isspace(*c) || !ft_isalnum(*c)))
			c++;
		if (*c && !ft_isspace(*c) && ft_isalpha(*c++))
			*(c - 1) = (char)ft_toupper(*(c - 1));
		while (*c && !ft_isspace(*c) && !ft_ispunct(*c++))
			*(c - 1) = (char)ft_tolower(*(c - 1));
	}
	return (str);
}
