/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:37:32 by aahizi-e          #+#    #+#             */
/*   Updated: 2018/11/24 20:41:39 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(const char *s)
{
	char	*p;
	char	*str;

	str = (char *)s;
	p = str;
	while (*str)
	{
		if (ft_isalpha(*str) && ft_islower(*str))
			*str = (char)ft_toupper(*str);
		str++;
	}
	return (p);
}
