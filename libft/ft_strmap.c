/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 04:52:01 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:45:33 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	n;
	char	*p;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (!f || !(p = ft_strnew(n)))
		return (NULL);
	while (n--)
		*(p + n) = f(*(char *)(s + n));
	return (p);
}
